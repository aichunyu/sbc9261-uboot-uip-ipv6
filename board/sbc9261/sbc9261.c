/*
 * (C) Copyright 2006
 * Ronetix
 * Added PM9261 support.
 *
 * (C) Copyright 2005
 * M. Amine SAYA ATMEL Rousset, France.
 * Added AT91SAM9261EK support.
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
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

#include <common.h>
#include <asm/arch/AT91SAM9261.h>
#include <asm/arch/pio.h>

#include <net.h>

/* ------------------------------------------------------------------------- */
/*
 * Miscelaneous platform dependent initialisations
 */
#ifdef  CONFIG_DRIVER_DM9000

void pm9261_dm9000_init (void) {

	// Configure SMC CS2 for DM9000
	AT91C_BASE_SMC-> SMC_SETUP2 = (AT91C_DM9000_NWE_SETUP |
					AT91C_DM9000_NCS_WR_SETUP |
					AT91C_DM9000_NRD_SETUP |
					AT91C_DM9000_NCS_RD_SETUP);

	AT91C_BASE_SMC-> SMC_PULSE2 = (AT91C_DM9000_NWE_PULSE |
					AT91C_DM9000_NCS_WR_PULSE |
					AT91C_DM9000_NRD_PULSE |
					AT91C_DM9000_NCS_RD_PULSE);

	AT91C_BASE_SMC-> SMC_CYCLE2 = (AT91C_DM9000_NWE_CYCLE |
					AT91C_DM9000_NRD_CYCLE);

#ifdef CONFIG_DM9000_USE_8BIT
	AT91C_BASE_SMC-> SMC_CTRL2 = (AT91C_SMC_READMODE |
				AT91C_SMC_WRITEMODE |
				AT91C_SMC_NWAITM_NWAIT_ENABLE_READY |
				AT91C_SMC_DBW_WIDTH_EIGTH_BITS |
				AT91C_DM9000_TDF);
#endif

#ifdef CONFIG_DM9000_USE_16BIT
	AT91C_BASE_SMC-> SMC_CTRL2 = (AT91C_SMC_READMODE |
				AT91C_SMC_WRITEMODE |
				AT91C_SMC_NWAITM_NWAIT_DISABLE |
				AT91C_SMC_BAT_BYTE_WRITE |
				AT91C_SMC_DBW_WIDTH_SIXTEEN_BITS |
				AT91C_DM9000_TDF);
#endif

	// Configure NWAIT signal
	// AT91F_PIO_CfgPeriph (AT91C_BASE_PIOC,AT91C_PC2_NWAIT,0);
}
#endif

int board_init (void) {
DECLARE_GLOBAL_DATA_PTR;

	// Enable Ctrlc
	console_init_f ();

	// Enable clocks for SMC and PIOA
	AT91C_BASE_PMC-> PMC_PCER = 1 << AT91C_ID_SYS;
	AT91C_BASE_PMC-> PMC_PCER = 1 << AT91C_ID_PIOA;

	// memory and cpu-speed are setup before relocation
	// so we do _nothing_ here

#ifdef CONFIG_LCD
	gd->fb_base = (unsigned long) LCD_BUFFER_ADDRESS;//AT91C_IRAM;
#endif

	// arch number of PM9261-Board
	gd-> bd-> bi_arch_number = MACH_TYPE_SBC9261;
	// adress of boot parameters
	gd-> bd-> bi_boot_params = PHYS_SDRAM + 0x100;
	return 0;
}

#ifdef CONFIG_DISPLAY_BOARDINFO
int checkboard (void) {
ulong i, diva, divb, mula, mulb, crystal, usbdiv;

	printf ("\nEmbest sbc9261 Board\n");
#ifdef CONFIG_UIP_STACK_SUPPORT
	printf (" - uIP stack enabled\n");
#endif
	i = *AT91C_PMC_PLLAR;
	mula = ((i >> 16) & 0x7ff) + 1;
	diva = i & 0xff;

	i = *AT91C_PMC_PLLBR;
	mulb = ((i >> 16) & 0x7ff) + 1;
	divb = i & 0xff;
	usbdiv = (i >> 28) & 0x3;

	i = *AT91C_PMC_MCFR;
	crystal = (i & 0xffff) * 32768 / 16;
	if (i & 0x10000) {
		printf ("  Crystal frequency: %i\n", crystal);
		printf ("  CPU frequency: %i\n",
			(crystal * mula) / diva);
		printf ("  Master clock frequency: %i\n",
			(crystal * mula) / diva / 2);
		printf ("  USB clock frequency: %i\n",
			((usbdiv == 0) ? ((crystal * mulb) / divb) :
				((usbdiv == 1) ? ((crystal * mulb) / divb / 2) :
				 ((crystal * mulb) / divb / 4)
				)
			));
	}
	printf ("\n");
	return 0;
}
#endif

int dram_init (void) {
DECLARE_GLOBAL_DATA_PTR;

	gd-> bd-> bi_dram [0]. start = PHYS_SDRAM;
	gd-> bd-> bi_dram [0]. size = PHYS_SDRAM_SIZE;
	return 0;
}


int board_late_init(void) {
DECLARE_GLOBAL_DATA_PTR;

	// Fix Ethernet Initialization Bug when starting Linux from U-Boot
#if (CONFIG_COMMANDS & CFG_CMD_NET)
	// adress of boot parameters
	gd-> bd-> bi_boot_params = PHYS_SDRAM + 0x100;
#ifdef CONFIG_DRIVER_DM9000
	// configure SMC's NCS2 to use it with DM9000 chip */
	pm9261_dm9000_init();
#endif
	eth_init (gd->bd);
#endif

	return 0;
}
