/*
  dm9000.c: Version 1.2 12/15/2003

	A Davicom DM9000 ISA NIC fast Ethernet driver for Linux.
	Copyright (C) 1997  Sten Wang

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

  (C)Copyright 1997-1998 DAVICOM Semiconductor,Inc. All Rights Reserved.

V0.11	06/20/2001	REG_0A bit3=1, default enable BP with DA match
	06/22/2001 	Support DM9801 progrmming
	 	 	E3: R25 = ((R24 + NF) & 0x00ff) | 0xf000
		 	E4: R25 = ((R24 + NF) & 0x00ff) | 0xc200
     		R17 = (R17 & 0xfff0) | NF + 3
		 	E5: R25 = ((R24 + NF - 3) & 0x00ff) | 0xc200
     		R17 = (R17 & 0xfff0) | NF

v1.00               	modify by simon 2001.9.5
	                change for kernel 2.4.x

v1.1   11/09/2001      	fix force mode bug

v1.2   03/18/2003       Weilun Huang <weilun_huang@davicom.com.tw>:
			Fixed phy reset.
			Added tx/rx 32 bit mode.
			Cleaned up for kernel merge.

--------------------------------------

       12/15/2003       Initial port to u-boot by Sascha Hauer <saschahauer@web.de>

TODO: Homerun NIC and longrun NIC are not functional, only internal at the
      moment.
*/

#include <common.h>
#include <command.h>
#include <net.h>
#include <asm/io.h>

#ifdef CONFIG_DRIVER_DM9000

#include "dm9000x.h"

/* Board/System/Debug information/definition ---------------- */

#define DM9801_NOISE_FLOOR	0x08
#define DM9802_NOISE_FLOOR	0x05

/* #define CONFIG_DM9000_DEBUG */

#ifdef CONFIG_DM9000_DEBUG
#define DM9000_DBG(fmt,args...) printf(fmt ,##args)
#else				/*  */
#define DM9000_DBG(fmt,args...)
#endif				/*  */
enum DM9000_PHY_mode { DM9000_10MHD = 0, DM9000_100MHD =
	    1, DM9000_10MFD = 4, DM9000_100MFD = 5, DM9000_AUTO =
	    8, DM9000_1M_HPNA = 0x10
};
enum DM9000_NIC_TYPE { FASTETHER_NIC = 0, HOMERUN_NIC = 1, LONGRUN_NIC = 2
};

/* Structure/enum declaration ------------------------------- */
typedef struct board_info {
	u32 runt_length_counter;	/* counter: RX length < 64byte */
	u32 long_length_counter;	/* counter: RX length > 1514byte */
	u32 reset_counter;	/* counter: RESET */
	u32 reset_tx_timeout;	/* RESET caused by TX Timeout */
	u32 reset_rx_status;	/* RESET caused by RX Statsus wrong */
	u16 tx_pkt_cnt;
	u16 queue_start_addr;
	u16 dbug_cnt;
	u8 phy_addr;
	u8 device_wait_reset;	/* device state */
	u8 nic_type;		/* NIC type */
	unsigned char srom[128];
} board_info_t;
board_info_t dmfe_info;

/* For module input parameter */
static int media_mode = DM9000_AUTO;
static u8 nfloor = 0;

/* function declaration ------------------------------------- */
int eth_init(bd_t * bd);
int eth_send(volatile void *, int);
int eth_rx(void);
void eth_halt(void);
static int dm9000_probe(void);
static u16 phy_read(int);
static void phy_write(int, u16);
#ifdef CONFIG_DM9000_HAVE_EEPROM
static u16 read_srom_word(int);
#endif
#ifdef CONFIG_DM9000_HAVE_1W_SERIAL
static void read_srom_1w_serial (u_char *s);
#endif
static u8 DM9000_ior(int);
static void DM9000_iow(int reg, u8 value);

/* DM9000 network board routine ---------------------------- */

#define DM9000_outb(d,r) ( *(volatile u8 *)r = d )
#define DM9000_outw(d,r) ( *(volatile u16 *)r = d )
#define DM9000_outl(d,r) ( *(volatile u32 *)r = d )
#define DM9000_inb(r) (*(volatile u8 *)r)
#define DM9000_inw(r) (*(volatile u16 *)r)
#define DM9000_inl(r) (*(volatile u32 *)r)

#ifdef CONFIG_DM9000_DEBUG
static void
dump_regs(void)
{
	DM9000_DBG("\n");
	DM9000_DBG("NCR   (0x00): %02x\n", DM9000_ior(0));
	DM9000_DBG("NSR   (0x01): %02x\n", DM9000_ior(1));
	DM9000_DBG("TCR   (0x02): %02x\n", DM9000_ior(2));
	DM9000_DBG("TSRI  (0x03): %02x\n", DM9000_ior(3));
	DM9000_DBG("TSRII (0x04): %02x\n", DM9000_ior(4));
	DM9000_DBG("RCR   (0x05): %02x\n", DM9000_ior(5));
	DM9000_DBG("RSR   (0x06): %02x\n", DM9000_ior(6));
	DM9000_DBG("ISR   (0xFE): %02x\n", DM9000_ior(ISR));
	DM9000_DBG("\n");
}
#endif				/*  */

/*
  Search DM9000 board, allocate space and register it
*/
int
dm9000_probe(void)
{
	u32 id_val;
	id_val = DM9000_ior(DM9000_VIDL);
	id_val |= DM9000_ior(DM9000_VIDH) << 8;
	id_val |= DM9000_ior(DM9000_PIDL) << 16;
	id_val |= DM9000_ior(DM9000_PIDH) << 24;
	if (id_val == DM9000_ID) {
		printf("dm9000 i/o: 0x%x, id: 0x%x \n", CONFIG_DM9000_BASE,
		       id_val);
		return 0;
	} else {
		printf("dm9000 not found at 0x%08x id: 0x%08x\n",
		       CONFIG_DM9000_BASE, id_val);
		return -1;
	}
}

/* Set PHY operationg mode
*/
static void
set_PHY_mode(void)
{
	u16 phy_reg4 = 0x01e1, phy_reg0 = 0x1000;
	if (!(media_mode & DM9000_AUTO)) {
		switch (media_mode) {
		case DM9000_10MHD:
			phy_reg4 = 0x21;
			phy_reg0 = 0x0000;
			break;
		case DM9000_10MFD:
			phy_reg4 = 0x41;
			phy_reg0 = 0x1100;
			break;
		case DM9000_100MHD:
			phy_reg4 = 0x81;
			phy_reg0 = 0x2000;
			break;
		case DM9000_100MFD:
			phy_reg4 = 0x101;
			phy_reg0 = 0x3100;
			break;
		}
		phy_write(4, phy_reg4);	/* Set PHY media mode */
		phy_write(0, phy_reg0);	/*  Tmp */
	}
	DM9000_iow(DM9000_GPCR, 0x01);	/* Let GPIO0 output */
	DM9000_iow(DM9000_GPR, 0x00);	/* Enable PHY */
}

/*
	Init HomeRun DM9801
*/
static void
program_dm9801(u16 HPNA_rev)
{
	__u16 reg16, reg17, reg24, reg25;
	if (!nfloor)
		nfloor = DM9801_NOISE_FLOOR;
	reg16 = phy_read(16);
	reg17 = phy_read(17);
	reg24 = phy_read(24);
	reg25 = phy_read(25);
	switch (HPNA_rev) {
	case 0xb900:		/* DM9801 E3 */
		reg16 |= 0x1000;
		reg25 = ((reg24 + nfloor) & 0x00ff) | 0xf000;
		break;
	case 0xb901:		/* DM9801 E4 */
		reg25 = ((reg24 + nfloor) & 0x00ff) | 0xc200;
		reg17 = (reg17 & 0xfff0) + nfloor + 3;
		break;
	case 0xb902:		/* DM9801 E5 */
	case 0xb903:		/* DM9801 E6 */
	default:
		reg16 |= 0x1000;
		reg25 = ((reg24 + nfloor - 3) & 0x00ff) | 0xc200;
		reg17 = (reg17 & 0xfff0) + nfloor;
	}
	phy_write(16, reg16);
	phy_write(17, reg17);
	phy_write(25, reg25);
}

/*
	Init LongRun DM9802
*/
static void
program_dm9802(void)
{
	__u16 reg25;
	if (!nfloor)
		nfloor = DM9802_NOISE_FLOOR;
	reg25 = phy_read(25);
	reg25 = (reg25 & 0xff00) + nfloor;
	phy_write(25, reg25);
}

/* Identify NIC type
*/
static void
identify_nic(void)
{
	struct board_info *db = &dmfe_info;	/* Point a board information structure */
	u16 phy_reg3;
	DM9000_iow(DM9000_NCR, NCR_EXT_PHY);
	phy_reg3 = phy_read(3);
	switch (phy_reg3 & 0xfff0) {
	case 0xb900:
		if (phy_read(31) == 0x4404) {
			db->nic_type = HOMERUN_NIC;
			program_dm9801(phy_reg3);
			DM9000_DBG("found homerun NIC\n");
		} else {
			db->nic_type = LONGRUN_NIC;
			DM9000_DBG("found longrun NIC\n");
			program_dm9802();
		}
		break;
	default:
		db->nic_type = FASTETHER_NIC;
		break;
	}
	DM9000_iow(DM9000_NCR, 0);
}

/* General Purpose dm9000 reset routine */
static void
dm9000_reset(void)
{
	DM9000_DBG("resetting\n");
	DM9000_iow(DM9000_NCR, NCR_RST);
	udelay(1000);		/* delay 1ms */
}

/* Initilize dm9000 board
*/
int
eth_init(bd_t * bd)
{
	int i, oft, lnk;
	DM9000_DBG("eth_init()\n");

#ifdef CONFIG_DRIVER_DM9000A
	DM9000_iow(DM9000_GPR, 0x01);	/*REG_1F bit0 activate phyxcer */
	udelay(500);
	DM9000_iow(DM9000_GPR, 0x00);	/*REG_1F bit0 activate phyxcer */
	udelay(20);		/* wait 2ms for PHY power-on ready */
#endif
	/* RESET device */
	dm9000_reset();
	dm9000_probe();

	/* NIC Type: FASTETHER, HOMERUN, LONGRUN */
	identify_nic();

#ifndef CONFIG_DRIVER_DM9000A
	/* GPIO0 on pre-activate PHY */
	DM9000_iow(DM9000_GPR, 0x00);	/*REG_1F bit0 activate phyxcer */
#endif
	/* Set PHY */
	set_PHY_mode();

	/* Program operating register */
	DM9000_iow(DM9000_NCR, 0x0);	/* only intern phy supported by now */
	DM9000_iow(DM9000_TCR, 0);	/* TX Polling clear */
	DM9000_iow(DM9000_BPTR, 0x3f);	/* Less 3Kb, 200us */
	DM9000_iow(DM9000_FCTR, FCTR_HWOT(3) | FCTR_LWOT(8));	/* Flow Control : High/Low Water */
	DM9000_iow(DM9000_FCR, 0x0);	/* SH FIXME: This looks strange! Flow Control */
	DM9000_iow(DM9000_SMCR, 0);	/* Special Mode */
	DM9000_iow(DM9000_NSR, NSR_WAKEST | NSR_TX2END | NSR_TX1END);	/* clear TX status */
	DM9000_iow(DM9000_ISR, 0x0f);	/* Clear interrupt status */

#ifdef CONFIG_DM9000_HAVE_EEPROM
	/* Set Node address */
	for (i = 0; i < 6; i++)
		((u16 *) bd->bi_enetaddr)[i] = read_srom_word(i);
#endif
#ifdef CONFIG_DM9000_HAVE_1W_SERIAL
	read_srom_1w_serial (bd->bi_enetaddr);
#endif
	printf("MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", bd->bi_enetaddr[0],
	       bd->bi_enetaddr[1], bd->bi_enetaddr[2], bd->bi_enetaddr[3],
	       bd->bi_enetaddr[4], bd->bi_enetaddr[5]);
	for (i = 0, oft = 0x10; i < 6; i++, oft++)
		DM9000_iow(oft, bd->bi_enetaddr[i]);
	for (i = 0, oft = 0x16; i < 8; i++, oft++)
		DM9000_iow(oft, 0xff);

	/* read back mac, just to be sure */
	for (i = 0, oft = 0x10; i < 6; i++, oft++) {
		lnk = DM9000_ior(oft);
		if (lnk != bd->bi_enetaddr[i]) {
			printf ("Cant set MAC addr[%i]: "
				"write %02X reset %02X\n",
				i, bd->bi_enetaddr[i], lnk);
		}
		DM9000_DBG("%02x:", lnk);
	}
	DM9000_DBG("\n");

	/* Activate DM9000 */
	DM9000_iow(DM9000_RCR, RCR_DIS_LONG | RCR_DIS_CRC | RCR_RXEN);	/* RX enable */
	DM9000_iow(DM9000_IMR, IMR_PAR);	/* Enable TX/RX interrupt mask */
	i = 0;
	while (!(phy_read(1) & 0x20)) {	/* autonegation complete bit */
		udelay(1000);
		i++;
		if (i == 10000) {
			printf("could not establish link\n");
			return 0;
		}
	}

	/* see what we've got */
	lnk = phy_read(17) >> 12;
	printf("operating at ");
	switch (lnk) {
	case 1:
		printf("10M half duplex ");
		break;
	case 2:
		printf("10M full duplex ");
		break;
	case 4:
		printf("100M half duplex ");
		break;
	case 8:
		printf("100M full duplex ");
		break;
	default:
		printf("unknown: %d ", lnk);
		break;
	}
	printf("mode\n");
	return 0;
}

/*
  Hardware start transmission.
  Send a packet to media from the upper layer.
*/
int
eth_send(volatile void *packet, int length)
{
	char *data_ptr;
	u32 tmplen, i;
	int tmo;

	DM9000_DBG("eth_send: length: %d\n", length);
	for (i = 0; i < length; i++) {
		if (i % 8 == 0)
			DM9000_DBG("\nSend: 02x: ", i);
		DM9000_DBG("%02x ", ((unsigned char *) packet)[i]);
	} DM9000_DBG("\n");

	/* Move data to DM9000 TX RAM */
	data_ptr = (char *) packet;
#ifdef CONFIG_DRIVER_DM9000A
	/* Set TX length to DM9000 */
	DM9000_iow(DM9000_TXPLL, length & 0xff);
	DM9000_iow(DM9000_TXPLH, (length >> 8) & 0xff);
#endif
	DM9000_outb(DM9000_MWCMD, DM9000_IO);

#ifdef CONFIG_DM9000_USE_8BIT
	/* Byte mode */
	for (i = 0; i < length; i++)
		DM9000_outb((data_ptr[i] & 0xff), DM9000_DATA);

#endif				/*  */
#ifdef CONFIG_DM9000_USE_16BIT
	tmplen = (length + 1) / 2;
	for (i = 0; i < tmplen; i++)
		DM9000_outw(((u16 *) data_ptr)[i], DM9000_DATA);

#endif				/*  */
#ifdef CONFIG_DM9000_USE_32BIT
	tmplen = (length + 3) / 4;
	for (i = 0; i < tmplen; i++)
		DM9000_outl(((u32 *) data_ptr)[i], DM9000_DATA);

#endif				/*  */

#ifndef CONFIG_DRIVER_DM9000A
	/* Set TX length to DM9000 */
	DM9000_iow(DM9000_TXPLL, length & 0xff);
	DM9000_iow(DM9000_TXPLH, (length >> 8) & 0xff);
#endif
	/* Issue TX polling command */
	DM9000_iow(DM9000_TCR, TCR_TXREQ);	/* Cleared after TX complete */

	/* wait for end of transmission */
	tmo = get_timer(0) + 5 * CFG_HZ;
	while (DM9000_ior(DM9000_TCR) & TCR_TXREQ) {
		if (get_timer(0) >= tmo) {
			printf ("transmission timeout\n");
			break;
		}
	}
#ifdef CONFIG_DRIVER_DM9000A
	udelay (1000);
#endif
	DM9000_DBG("transmit done\n\n");
	return 0;
}

/*
  Stop the interface.
  The interface is stopped when it is brought.
*/
void
eth_halt(void)
{
	DM9000_DBG("eth_halt\n");

	/* RESET device */
	phy_write(0, 0x8000);	/* PHY RESET */
	DM9000_iow(DM9000_GPR, 0x01);	/* Power-Down PHY */
	DM9000_iow(DM9000_IMR, 0x80);	/* Disable all interrupt */
	DM9000_iow(DM9000_RCR, 0x00);	/* Disable RX */
}

/*
  Received a packet and pass to upper layer
*/
int
eth_rx(void)
{
	u8 rxbyte, *rdptr = (u8 *) NetRxPackets[0];
	u16 RxStatus, RxLen = 0;
	u32 tmplen, i;
#ifdef CONFIG_DM9000_USE_32BIT
	u32 tmpdata;
#endif

	/* Check packet ready or not */
	DM9000_ior(DM9000_MRCMDX);	/* Dummy read */
	rxbyte = DM9000_inb(DM9000_DATA);	/* Got most updated data */
#if CONFIG_DRIVER_DM9000A
	if ((rxbyte & 1) == 0) {
		DM9000_ior(DM9000_ISR);
		return 0;
	}
#else
	if (rxbyte == 0)
		return 0;

	/* Status check: this byte must be 0 or 1 */
	if (rxbyte > 1) {
		DM9000_iow(DM9000_RCR, 0x00);	/* Stop Device */
		DM9000_iow(DM9000_ISR, 0x80);	/* Stop INT request */
		DM9000_DBG("rx status check: %d\n", rxbyte);
	}
#endif
	DM9000_DBG("receiving packet\n");

	/* A packet ready now  & Get status/length */
	DM9000_outb(DM9000_MRCMD, DM9000_IO);

#ifdef CONFIG_DM9000_USE_8BIT
	RxStatus = DM9000_inb(DM9000_DATA) + (DM9000_inb(DM9000_DATA) << 8);
	RxLen = DM9000_inb(DM9000_DATA) + (DM9000_inb(DM9000_DATA) << 8);

#endif				/*  */
#ifdef CONFIG_DM9000_USE_16BIT
	RxStatus = DM9000_inw(DM9000_DATA);
	RxLen = DM9000_inw(DM9000_DATA);

#endif				/*  */
#ifdef CONFIG_DM9000_USE_32BIT
	tmpdata = DM9000_inl(DM9000_DATA);
	RxStatus = tmpdata;
	RxLen = tmpdata >> 16;

#endif				/*  */
	DM9000_DBG("rx status: 0x%04x rx len: %d\n", RxStatus, RxLen);

	/* Move data from DM9000 */
	/* Read received packet from RX SRAM */
#ifdef CONFIG_DM9000_USE_8BIT
	for (i = 0; i < RxLen; i++)
		rdptr[i] = DM9000_inb(DM9000_DATA);

#endif				/*  */
#ifdef CONFIG_DM9000_USE_16BIT
	tmplen = (RxLen + 1) / 2;
	for (i = 0; i < tmplen; i++)
		((u16 *) rdptr)[i] = DM9000_inw(DM9000_DATA);

#endif				/*  */
#ifdef CONFIG_DM9000_USE_32BIT
	tmplen = (RxLen + 3) / 4;
	for (i = 0; i < tmplen; i++)
		((u32 *) rdptr)[i] = DM9000_inl(DM9000_DATA);

#endif				/*  */
	if ((RxStatus & 0xbf00) || (RxLen < 0x40)
	    || (RxLen > DM9000_PKT_MAX)) {
		if (RxStatus & 0x100) {
			printf("rx fifo error\n");
		}
		if (RxStatus & 0x200) {
			printf("rx crc error\n");
		}
		if (RxStatus & 0x8000) {
			printf("rx length error\n");
		}
		if (RxLen > DM9000_PKT_MAX) {
			printf("rx length too big\n");
			dm9000_reset();
		}
	} else {

		/* Pass to upper layer */
		DM9000_DBG("passing packet to upper layer\n");
		NetReceive(NetRxPackets[0], RxLen);
		return RxLen;
	}
	return 0;
}

#ifdef CONFIG_DM9000_HAVE_EEPROM
/*
  Read a word data from SROM
*/
static u16
read_srom_word(int offset)
{
	DM9000_iow(DM9000_EPAR, offset);
	DM9000_iow(DM9000_EPCR, 0x4);
	udelay(200);
	DM9000_iow(DM9000_EPCR, 0x0);
	return (DM9000_ior(DM9000_EPDRL) + (DM9000_ior(DM9000_EPDRH) << 8));
}
#endif

#ifdef CONFIG_DM9000_HAVE_1W_SERIAL
#ifndef CONFIG_SBC9261
#error Only PM9261 board is supported!
#endif
#include <asm/arch/AT91SAM9261.h>
#include <asm/arch/pio.h>

#define W1_PIN AT91C_PIO_PA7

static void w1_set (int x) {

	if (x) {
		AT91C_BASE_PIOA-> PIO_SODR = W1_PIN;	// set
		AT91C_BASE_PIOA-> PIO_ODR = W1_PIN;	// input
	} else {
		AT91C_BASE_PIOA-> PIO_CODR = W1_PIN;	// clear
		AT91C_BASE_PIOA-> PIO_OER = W1_PIN;	// output
	}
}

static int w1_get (void) {

	AT91C_BASE_PIOA-> PIO_ODR = W1_PIN;		// input
	return (AT91C_BASE_PIOA-> PIO_PDSR & W1_PIN) ? 1 : 0;// pin data status
}

#define DS_PIN			GPIO_23
#define DS_READ_TRIES		10
#define DS_COMMAND_READ_ROM	0x33

static const uint8_t ds_table[] =
{
       0, 94, 188, 226, 97, 63, 221, 131, 194, 156, 126, 32, 163, 253, 31, 65,
       157, 195, 33, 127, 252, 162, 64, 30, 95, 1, 227, 189, 62, 96, 130, 220,
       35, 125, 159, 193, 66, 28, 254, 160, 225, 191, 93, 3, 128, 222, 60, 98,
       190, 224, 2, 92, 223, 129, 99, 61, 124, 34, 192, 158, 29, 67, 161, 255,
       70, 24, 250, 164, 39, 121, 155, 197, 132, 218, 56, 102, 229, 187, 89, 7,
       219, 133, 103, 57, 186, 228, 6, 88, 25, 71, 165, 251, 120, 38, 196, 154,
       101, 59, 217, 135, 4, 90, 184, 230, 167, 249, 27, 69, 198, 152, 122, 36,
       248, 166, 68, 26, 153, 199, 37, 123, 58, 100, 134, 216, 91, 5, 231, 185,
       140, 210, 48, 110, 237, 179, 81, 15, 78, 16, 242, 172, 47, 113, 147, 205,
       17, 79, 173, 243, 112, 46, 204, 146, 211, 141, 111, 49, 178, 236, 14, 80,
       175, 241, 19, 77, 206, 144, 114, 44, 109, 51, 209, 143, 12, 82, 176, 238,
       50, 108, 142, 208, 83, 13, 239, 177, 240, 174, 76, 18, 145, 207, 45, 115,
       202, 148, 118, 40, 171, 245, 23, 73, 8, 86, 180, 234, 105, 55, 213, 139,
       87, 9, 235, 181, 54, 104, 138, 212, 149, 203, 41, 119, 244, 170, 72, 22,
       233, 183, 85, 11, 136, 214, 52, 106, 43, 117, 151, 201, 74, 20, 246, 168,
       116, 42, 200, 150, 21, 75, 169, 247, 182, 232, 10, 84, 215, 137, 107, 53
};
//============================================================================
//
//
//                   BYTE  CrcDallas( BYTE *src, int len )
//
//                       DALLAS ONE-WIRE CRC
//
//   Parameters:
//        src -> Pointer to array of bytes
//        len -> Length of array (include the CRC sum - last byte)
//
//   Return:
//        0 -> If calculated CRC sum is OK
//        Non zero -> If error is occurred
//
//   Description:
//        Caclulate CRC-8 of given array 'src' with length 'len'
//        Used 8-bit CRC sum with DALLAS fix polynom 0x31
//
//============================================================================
static int  ds_crc (uint8_t *src, int len)
{
int ii;
uint8_t *pp, crc;

	pp = (uint8_t *) ds_table;

	for (ii = crc = 0; ii < len; ii++ )
		crc = *(pp +  (crc ^ src [ii]));

	return (int)crc;
}


//============================================================================
//
//                          int ds_reset(void)
//
// Parameter: None
//
// Return:
//      ENOERR  -> If no error
//      EINTR   -> If not 'presence pulse' is detected
//
// Description:
//      Make initialization procedure "Reset and Presence Pulses"
//
//============================================================================
#define tRSTL           600        // 480uS < tRSTL < 960uS
#define tRSTH           600        // 480uS < tRSTH < 960uS
#define tPDHmin          10        // 15uS
#define tPDHmax         100        // 60uS
#define tPDLmin          50        // 60uS
#define tPDLmax         250        // 240uS
#define tREC             10
static int ds_reset(void)
{
       // Reset pulse
       //============
	w1_set (0);
	udelay (tRSTL);
	w1_set (1);
	udelay (tRSTH);
	// Return 0 if no error is occurred
	// ================================
	return 0;
}

//============================================================================
//
//                   void write_one(void)
//
// Parameter: None
//
// Return: None
//
// Description:
//      Make Write-One Time Slot
//
//============================================================================
#define tLOW1           10
#define tSLOT           80

static void ds_write_one (void)
{
	w1_set (0);
	udelay (tLOW1);
	w1_set (1);
	udelay (tSLOT - tLOW1);
	udelay (tREC );
}

//============================================================================
//
//                         void write_zero(void)
//
// Parameter: None
//
// Return: None
//
// Description:
//     Make Write-Zero Time Slot
//
//============================================================================
static void ds_write_zero (void)
{
	w1_set (0);
	udelay (tSLOT);
	w1_set (1);
	udelay (tREC);
}

//============================================================================
//
//                      int ReadData( void )
//
// Parameter: None
//
// Return: None
//
// Description: Make Read-data Time Slot
//
//============================================================================
#define tLOWR             2
#define tRDV             15
#define tRELEASE         30
static int ds_read_data(void)
{
int ret;

	w1_set (0);
	udelay (tLOWR);
	w1_set (1);

	udelay (5);

	ret = w1_get ();

	udelay (tRELEASE);
	udelay (tREC);

	return ret;
}

//============================================================================
//
//                             void ds_send_byte(BYTE ch)
//
//
// Parameter:
//      ch  ->  byte to send
//
// Returns: None
//
// Description:
//      Send a byte to DS2401
//
//============================================================================
static void ds_send_byte (uint8_t ch)
{
uint8_t mask;

	for (mask = 0x01; mask; mask <<= 1)
		if (ch & mask)
			ds_write_one ();
		else
			ds_write_zero ();
}

//============================================================================
//
//                                  ds_read_byte
//
// Parameter:
//      None
//
// Return:
//      The data read from DS2401
//
// Description:
//      Read a byte from DS2401
//
//============================================================================
static uint8_t ds_read_byte(void)
{
uint8_t mask, ret;

	for (ret = 0, mask = 0x01; mask; mask <<= 1)
		if (ds_read_data())
			ret |= mask;
	return ret;
}

//=====================================================================
//                      ds_init()
//                      ----------
//
//              Read DS2401 module and fill the array
//
//=====================================================================
static void read_srom_1w_serial (u_char *s) {
uint8_t DS2401_rom [8];
int ii, tries, crc;


	// Prepare PIO pin
	//================
	AT91C_BASE_PIOA->PIO_ODR  = W1_PIN;	// input
	AT91C_BASE_PIOA->PIO_PER = W1_PIN;	// enable
	AT91C_BASE_PIOA->PIO_PPUER = W1_PIN;	// pull-up

	for (tries = 0; tries < DS_READ_TRIES; tries++ ) {
		// Reset the DS2401
		// ================
		if (ds_reset ()) continue;

		// Send command READ ROM
		// =====================
		ds_send_byte (DS_COMMAND_READ_ROM);

		// Read 64-bit unique number
		// =========================
		for (ii = 0; ii < 8; ii++)
		{
			DS2401_rom [ii] = ds_read_byte ();
			udelay(200);
		}


//		printf ("%i read: 0x%02x 0x%02x 0x%02x 0x%02x "
//			"0x%02x 0x%02x 0x%02x\n",
//			tries,DS2401_rom[0],DS2401_rom[1],DS2401_rom[2],
//			DS2401_rom[3],DS2401_rom[4],DS2401_rom[5],
//			DS2401_rom[6],DS2401_rom[7]);

		crc = ds_crc( DS2401_rom, sizeof(DS2401_rom)-1 );
//		printf ("%i crc=0x%02x 0x%02x \n",tries,crc,
//			DS2401_rom[sizeof(DS2401_rom)-1]);
		if ( crc == DS2401_rom[sizeof(DS2401_rom)-1] )
			break;
       }

	if (tries == DS_READ_TRIES) return;
	s [0] = 0x02;
	s [1] = DS2401_rom [5];
	s [2] = DS2401_rom [4];
	s [3] = DS2401_rom [3];
	s [4] = DS2401_rom [2];
	s [5] = DS2401_rom [1];
}
#endif


/*
   Read a byte from I/O port
*/
static u8
DM9000_ior(int reg)
{
	DM9000_outb(reg, DM9000_IO);
	return DM9000_inb(DM9000_DATA);
}

/*
   Write a byte to I/O port
*/
static void
DM9000_iow(int reg, u8 value)
{
	DM9000_outb(reg, DM9000_IO);
	DM9000_outb(value, DM9000_DATA);
}

/*
   Read a word from phyxcer
*/
static u16
phy_read(int reg)
{
	u16 val;

	/* Fill the phyxcer register into REG_0C */
	DM9000_iow(DM9000_EPAR, DM9000_PHY | reg);
	DM9000_iow(DM9000_EPCR, 0xc);	/* Issue phyxcer read command */
	udelay(100);		/* Wait read complete */
	DM9000_iow(DM9000_EPCR, 0x0);	/* Clear phyxcer read command */
	val = (DM9000_ior(DM9000_EPDRH) << 8) | DM9000_ior(DM9000_EPDRL);

	/* The read data keeps on REG_0D & REG_0E */
	DM9000_DBG("phy_read(%d): %d\n", reg, val);
	return val;
}

/*
   Write a word to phyxcer
*/
static void
phy_write(int reg, u16 value)
{

	/* Fill the phyxcer register into REG_0C */
	DM9000_iow(DM9000_EPAR, DM9000_PHY | reg);

	/* Fill the written data into REG_0D & REG_0E */
	DM9000_iow(DM9000_EPDRL, (value & 0xff));
	DM9000_iow(DM9000_EPDRH, ((value >> 8) & 0xff));
	DM9000_iow(DM9000_EPCR, 0xa);	/* Issue phyxcer write command */
	udelay(500);		/* Wait write complete */
	DM9000_iow(DM9000_EPCR, 0x0);	/* Clear phyxcer write command */
	DM9000_DBG("phy_write(reg:%d, value:%d)\n", reg, value);
}
#endif				/* CONFIG_DRIVER_DM9000 */
