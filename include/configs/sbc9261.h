/*
 * (C) Copyright 2006 Ronetix
 *
 * Configuation settings for the Ronetix PM9261 board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* ARM asynchronous clock */

#define AT91C_CRYSTAL		18432000

#define MASTER_PLL_DIV		15	
#define MASTER_PLL_MUL		162
#define MAIN_PLL_DIV		2

#define AT91C_MAIN_CLOCK	(AT91C_CRYSTAL/MASTER_PLL_DIV*MASTER_PLL_MUL)
#define AT91C_MASTER_CLOCK	(AT91C_MAIN_CLOCK/MAIN_PLL_DIV)


/* from 18.432 MHz crystal (18432000 / 1 * 11) */
//#define AT91C_MAIN_CLOCK	199065600
/* peripheral clock (AT91C_MAIN_CLOCK / 2) */
//#define AT91C_MASTER_CLOCK	99532800

/* from 18.432 MHz crystal (18432000 / 1 * 13) */
//#define AT91C_MAIN_CLOCK	239616000
/* peripheral clock (AT91C_MAIN_CLOCK / 2) */
//#define AT91C_MASTER_CLOCK	119808000


/* slow clock */
#define AT91_SLOW_CLOCK		32768

#define CFG_HZ			100

/* on an Ronexit PM9261 Board */
#define CONFIG_SBC9261		1
/* we don't need IRQ/FIQ stuff */
#undef  CONFIG_USE_IRQ
/* enable passing of ATAGs */
#define CONFIG_CMDLINE_TAG	        1
#define CONFIG_SETUP_MEMORY_TAGS        1
#define CONFIG_INITRD_TAG	        1
//#define CONFIG_SPI		        1
#define CFG_LONGHELP			1
#define CONFIG_DISPLAY_BOARDINFO	1
#define CFG_64BIT_VSPRINTF              1

/* Network settings */
#define CONFIG_IPADDR		10.1.1.20
#define CONFIG_GATEWAYIP	10.1.1.10
#define CONFIG_ETHADDR		DE:AD:BE:EF:01:01
#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_SERVERIP		10.1.1.10
#define CONFIG_HOSTNAME		SBC9261

#ifdef CONFIG_UIP_STACK_SUPPORT
#define CONFIG_UIP_NTWK_PROCESS_TIMEOUT  2 
#define CONFIG_IP6PREFIX_LEN    64
#define CONFIG_SERVERIP6	2001:beef::10	
#define CONFIG_GATEWAYIP6	2001:beef::100
#define CONFIG_IP6ADDR		2001:beef::20	
#endif /* CONFIG_UIP_STACK_SUPPORT */


#define CONFIG_ENV_OVERWRITE	1

#undef CONFIG_SKIP_LOWLEVEL_INIT

/*
 * Size of malloc() pool
 */
#define CFG_MALLOC_LEN	(CFG_ENV_SIZE + 256*1024)
/* size in bytes reserved for initial data */
#define CFG_GBL_DATA_SIZE	128

#define CONFIG_BAUDRATE         115200

/*
 * Hardware drivers
 */

/* define one of these to choose the DBGU, USART0  or USART1 as console */
#define CONFIG_DBGU		1
#undef CONFIG_USART0
#undef CONFIG_USART1
#undef CONFIG_USART2

/* don't include RTS/CTS flow control support	*/
#undef	CONFIG_HWFLOW

/* disable modem initialization stuff */
#undef	CONFIG_MODEM_SUPPORT

#define CONFIG_BOOTDELAY	        15	
#define CONFIG_BOOTCOMMAND		"run flashboot"
#define CONFIG_ROOTPATH			/home/nfs/rootfs
#define CONFIG_AUTOBOOT_PROMPT		"autoboot in %d seconds\n"

#define BOARD_LATE_INIT			1

#define CONFIG_COMMANDS		\
		       ((CONFIG_CMD_DFL	| \
                        CFG_CMD_NET | \
			CFG_CMD_PING | \
			CFG_CMD_DHCP | \
                        CFG_CMD_ENV | \
			CFG_CMD_FLASH | \
                        CFG_CMD_USB | \
			CFG_CMD_NAND | \
			CFG_CMD_AUTOSCRIPT | \
			CFG_CMD_ELF | \
			CFG_CMD_JFFS2 | \
			CFG_CMD_FAT ) & \
		      ~(CFG_CMD_BDI | \
			CFG_CMD_FPGA | \
			CFG_CMD_MISC | \
			CFG_CMD_LOADS))

// CFG_CMD_DISPLAY

/* this must be included AFTER the definition of CONFIG_COMMANDS (if any) */
#include <cmd_confdefs.h>

#define CONFIG_JFFS2_CMDLINE
#define CONFIG_JFFS2_NAND		1

#define MTDIDS_DEFAULT	 	"nor0=physmap-flash.0,nand0=nand"
#define MTDPARTS_DEFAULT		\
	"mtdparts=physmap-flash.0:"	\
		"256k(u-boot)ro,"	\
		"64k(u-boot-env)ro,"	\
		"1344k(kernel),"	\
		"-(rootfs);"		\
	"nand:-(nand)"


#define CONFIG_BOOTARGS "noinitrd root=/dev/mtdblock1 rootfstype=yaffs2 console=ttySAC0,115200"

#define CONFIG_EXTRA_ENV_SETTINGS				\
	"mtdids=" MTDIDS_DEFAULT "\0"				\
	"mtdparts=" MTDPARTS_DEFAULT "\0"			\
	"partition=nand0,0\0"					\
	"ramargs=setenv bootargs $(bootargs) $(mtdparts)\0"	\
	"nfsargs=setenv bootargs root=/dev/nfs rw "		\
		"nfsroot=$(serverip):$(rootpath) $(mtdparts)\0"	\
	"addip=setenv bootargs $(bootargs) "			\
		"ip=$(ipaddr):$(serverip):$(gatewayip):$(netmask)"\
		":$(hostname):eth0:off\0"			\
	"ramboot=tftpboot 0x22000000 vmImage;"			\
		"run ramargs;run addip;bootm 22000000\0"	\
	"nfsboot=tftpboot 0x22000000 vmImage;"			\
		"run nfsargs;run addip;bootm 22000000\0"	\
	"flashboot=run ramargs;bootm 0x10050000\0"	\
	""






//#define CFG_NO_FLASH
//#define CFG_FLASH_CFI			/* The flash is CFI compatible	*/
//#define CFG_FLASH_CFI_DRIVER		/* Use common CFI driver	*/
//#define CFG_FLASH_CFI_AMD_RESET


/*
 * Flash settings
 *
 */

//#define CFG_FLASH_CFI			/* The flash is CFI compatible	*/
//#define CFG_FLASH_CFI_DRIVER		/* Use common CFI driver	*/
//#define CFG_FLASH_CFI_AMD_RESET

#define CFG_ENV_IS_IN_FLASH		1

/* after u-boot.bin */
#define CFG_ENV_ADDR			(CFG_FLASH_BASE+ 0x40000)
#define CFG_ENV_OFFSET			0x40000
#define CFG_ENV_SIZE			0x10000
/* Total Size of Environment Sector */
#define CFG_ENV_SECT_SIZE		0x10000

/* JFFS Partition offset set  */
#define CFG_JFFS2_FIRST_BANK 0
#define CFG_JFFS2_NUM_BANKS  1
/* 512k reserved for u-boot */
#define CFG_JFFS2_FIRST_SECTOR		11

/*
 * following timeouts shall be used once the
 * Flash real protection is enabled
 */
#define CFG_FLASH_LOCK_TOUT		5	/* Timeout for Flash Set Lock Bit (in ms) */
#define CFG_FLASH_UNLOCK_TOUT		10000	/* Timeout for Flash Clear Lock Bits (in ms) */


#define NAND_MAX_CHIPS			1	/* Max number of NAND devices	*/
#define CFG_MAX_NAND_DEVICE		1	/* Max number of NAND devices	*/
#define SECTORSIZE			512
#define CFG_NAND_BASE			0x40000000
#define CONFIG_NEW_NAND_CODE

#define ADDR_COLUMN			1
#define ADDR_PAGE			2
#define ADDR_COLUMN_PAGE		3

#define NAND_ChipID_UNKNOWN		0
#define NAND_MAX_FLOORS			1
#undef  CFG_NAND_WP

#define AT91_SMART_MEDIA_ALE		(1 << 22)	/* our ALE is AD22 */
#define AT91_SMART_MEDIA_CLE		(1 << 21)	/* our CLE is AD21 */


/* These timings are specific to MT29F2G16AAB 256Mb (Micron)
 * at MCK = 119808000 Hz
 */

#define AT91C_SM_NWE_SETUP	(3 << 0)
#define AT91C_SM_NCS_WR_SETUP	(3 << 8)
#define AT91C_SM_NRD_SETUP	(3 << 16)
#define AT91C_SM_NCS_RD_SETUP	(3 << 24)

#define AT91C_SM_NWE_PULSE 	(4 << 0)
#define AT91C_SM_NCS_WR_PULSE	(4 << 8)
#define AT91C_SM_NRD_PULSE	(4 << 16)
#define AT91C_SM_NCS_RD_PULSE	(4 << 24)

#define AT91C_SM_NWE_CYCLE 	(8 << 0)
#define AT91C_SM_NRD_CYCLE	(8 << 16)

#define AT91C_SM_TDF	        (0x16 << 16)



#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM			0x20000000
#define PHYS_SDRAM_SIZE			0x4000000  /* 64 megs */

#define CFG_MEMTEST_START		PHYS_SDRAM
#define CFG_MEMTEST_END		(CFG_MEMTEST_START + PHYS_SDRAM_SIZE - 524288*2)

#define CONFIG_DRIVER_ETHER		1
#define CONFIG_DRIVER_DM9000		1
#define CONFIG_DRIVER_DM9000A		1
#undef CONFIG_DM9000_HAVE_EEPROM	/* MAC address is in environment */
#define CONFIG_DM9000_HAVE_1W_SERIAL	1 /* MAC address is in 1w serial */

#define CONFIG_NET_RETRY_COUNT		250
#define CONFIG_TFTP_TIMEOUT		250
#define CONFIG_DM9000_BASE		0x30000000
#define DM9000_IO			CONFIG_DM9000_BASE
#define DM9000_DATA			(CONFIG_DM9000_BASE+4)
#undef  CONFIG_DM9000_USE_8BIT
#define CONFIG_DM9000_USE_16BIT		1
#undef  CONFIG_DM9000_USE_32BIT
#undef  CONFIG_DM9000_DEBUG
//#define CONFIG_DM9000_DEBUG		1

#ifdef  CONFIG_DRIVER_DM9000
/*
 * SMC Chip Select 2 Timings for DM9000 (davicom).
 * These timings were calculated for MASTER_CLOCK = 119808000
 * according to DM9000 timings. Refer to SMC user interface
 * in AT91SAM9261 datasheet to learn how to regenerate these
 * values in case MASTER_CLOCK changes.
 */
#define AT91C_DM9000_NWE_SETUP	        (4 << 0)
#define AT91C_DM9000_NCS_WR_SETUP	(2 << 8)
#define AT91C_DM9000_NRD_SETUP	        (4 << 16)
#define AT91C_DM9000_NCS_RD_SETUP	(2 << 24)

#define AT91C_DM9000_NWE_PULSE 	        (8 << 0)
#define AT91C_DM9000_NCS_WR_PULSE	(16 << 8)
#define AT91C_DM9000_NRD_PULSE	        (8 << 16)
#define AT91C_DM9000_NCS_RD_PULSE	(16 << 24)

#define AT91C_DM9000_NWE_CYCLE 	        (32 << 0)
#define AT91C_DM9000_NRD_CYCLE	        (32 << 16)

#define AT91C_DM9000_TDF	        (1 << 16)


#endif /* CONFIG_DRIVER_DM9000 */




#define CONFIG_HAS_DATAFLASH		1
#define CFG_SPI_WRITE_TOUT		(50*CFG_HZ)

/* AC Characteristics */
/* DLYBS = tCSS = 250ns min and DLYBCT = tCSH = 250ns */
#define DATAFLASH_TCSS			(0x1a << 16)
#define DATAFLASH_TCHS			(0x1 << 24)

#define CFG_MAX_DATAFLASH_BANKS 	2
#define CFG_MAX_DATAFLASH_PAGES 	16384
#define CFG_DATAFLASH_LOGIC_ADDR_CS0	0xC0000000	/* Logical adress for CS0 */
#define CFG_DATAFLASH_LOGIC_ADDR_CS3	0xD0000000	/* Logical adress for CS3 */

#define PHYS_FLASH_1			0x10000000
#define PHYS_FLASH_SIZE			0x800000  /* 2 megs main flash */
#define CFG_FLASH_BASE			PHYS_FLASH_1
#define CFG_MAX_FLASH_BANKS		1
#define CFG_MAX_FLASH_SECT		256
#define CFG_FLASH_ERASE_TOUT		(17*CFG_HZ) /* Timeout for Flash Erase */
#define CFG_FLASH_ERASEBLOCK_TOUT	(5*CFG_HZ) /* Timeout for Block Erase (in ms) */
#define CFG_FLASH_WRITE_TOUT		(5*CFG_HZ) /* Timeout for Flash Write */

/* Add LCD stuff */
/* #define  CONFIG_LCD			1*/
/* #undef  CONFIG_LCD_LOGO */
#define CONFIG_LCD_LOGO			1
#undef LCD_TEST_PATTERN
#define CONFIG_LCD_INFO			1
#define CONFIG_LCD_INFO_BELOW_LOGO	1
/* #define CFG_INVERT_COLORS */
#define CFG_WHITE_ON_BLACK		1
#define LCD_BUFFER_ADDRESS		0x23000000
#define LOGO_BMP			""

/* Add USB stuff */
#define CONFIG_USB_OHCI			1
#define CONFIG_USB_STORAGE		1
#define CONFIG_DOS_PARTITION	        1
#define LITTLEENDIAN 			1

#define CFG_LOAD_ADDR		0x23f00000  /* default load address */

#define CFG_BOOT_SIZE		0x00 /* 0 KBytes */
#define CFG_U_BOOT_BASE		PHYS_FLASH_1
#define CFG_U_BOOT_SIZE		0x30000 /* 192 KBytes */

#define CFG_BAUDRATE_TABLE	{115200 , 19200, 38400, 57600, 9600 }
#define CFG_CONSOLE_IS_SERIAL
#undef  CFG_CONSOLE_IS_LCD
#define CFG_PROMPT		"Mini9261> "	/* Monitor Command Prompt */
#define CFG_CBSIZE		256		/* Console I/O Buffer Size */
#define CFG_MAXARGS		16		/* max number of command args */
#define CFG_PBSIZE		(CFG_CBSIZE+sizeof(CFG_PROMPT)+16) /* Print Buffer Size */


#ifndef __ASSEMBLY__
/*-----------------------------------------------------------------------
 * Board specific extension for bd_info
 *
 * This structure is embedded in the global bd_info (bd_t) structure
 * and can be used by the board specific code (eg board/...)
 */

struct bd_info_ext {
	/* helper variable for board environment handling
	 *
	 * env_crc_valid == 0    =>   uninitialised
	 * env_crc_valid  > 0    =>   environment crc in flash is valid
	 * env_crc_valid  < 0    =>   environment crc in flash is invalid
	 */
	int env_crc_valid;
};
#endif


#define CONFIG_STACKSIZE	(32*1024)	/* regular stack */

#ifdef CONFIG_USE_IRQ
#error CONFIG_USE_IRQ not supported
#endif

#endif
