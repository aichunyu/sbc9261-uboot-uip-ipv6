/*
 * Memory Setup stuff - taken from blob memsetup.S
 *
 * Copyright (C) 1999 2000 2001 Erik Mouw (J.A.K.Mouw@its.tudelft.nl) and
 *		       Jan-Derk Bakker (J.D.Bakker@its.tudelft.nl)
 *
 * Modified for the Ronetix PM9261 board
 * (C) Copyright 2006 Ronetix
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <config.h>
#include <version.h>
#include <asm/arch/hardware.h>

#ifndef CONFIG_SKIP_LOWLEVEL_INIT

#define SDRAM 0x20000000		/* address of the SDRAM */

/* values */

/* clocks */
#define MOR_VAL 0x00002001		/* CKGR_MOR - enable main osc. */
#define PLLAR_VAL (0x2000B000 | ((MASTER_PLL_MUL - 1)<< 16) | (MASTER_PLL_DIV))
/* #define PLLAR_VAL 0x200CBF01 */	/* 239.616000 MHz for PCK */
#define PLLBR_VAL 0x10483E0E		/* 48.054857 MHz for USB) */

#define MCKR_VAL 0x00000102		/* PCK/2 = MCK Master Clock from PLLA*/

#define WDTC_WDMR_VAL 0x3fff8fff	/* disable watchdog */
#define PIOC_PDR_VAL1 0xFFFF0000	/* define PDC[31:16] as DATA[31:16] */
#define PIOC_PPUDR_VAL 0xFFFF0000	/* no pull-up for D[31:16] */
#define MATRIX_EBICSA_VAL 0x10A		/* EBI_CSA, no pull-ups for D[15:0],
					CS1 SDRAM, CS3 NAND Flash */

/* SDRAM */
#define SDRC_MR_VAL1 0			/* SDRAMC_MR Mode register */
#define SDRC_TR_VAL1 0x13C		/* SDRAMC_TR - Refresh Timer register*/
#define SDRC_CR_VAL 0x85237279		/* SDRAMC_CR - Configuration register*/
#define SDRC_MDR_VAL 0			/*  Memory Device Register -> SDRAM */
#define SDRC_MR_VAL2 0x00000002		/*  SDRAMC_MR */
#define SDRAM_VAL1 0			/*  SDRAM_BASE */
#define SDRC_MR_VAL3 4			/*  SDRC_MR */
#define SDRAM_VAL2 0			/*  SDRAM_BASE */
#define SDRAM_VAL3 0			/*  SDRAM_BASE */
#define SDRAM_VAL4 0			/*  SDRAM_BASE */
#define SDRAM_VAL5 0			/*  SDRAM_BASE */
#define SDRAM_VAL6 0			/*  SDRAM_BASE */
#define SDRAM_VAL7 0			/*  SDRAM_BASE */
#define SDRAM_VAL8 0			/*  SDRAM_BASE */
#define SDRAM_VAL9 0			/*  SDRAM_BASE */
#define SDRC_MR_VAL4 3			/*  SDRC_MR */
#define SDRAM_VAL10 0			/* SDRAM_BASE */
#define SDRC_MR_VAL5 0			/*  SDRC_MR */
#define SDRAM_VAL11 0			/*  SDRAM_BASE */
#define SDRC_TR_VAL2 1200		/* SDRAM_TR */
#define SDRAM_VAL12 0			/*  SDRAM_BASE */

/* setup CS0 (NOR Flash) - 16-bit, 15 WS */
#define SMC_SETUP0_VAL 0x0A0A0A0A	/*  SMC_SETUP */
#define SMC_PULSE0_VAL 0x0B0B0B0B	/*  SMC_PULSE */
#define SMC_CYCLE0_VAL 0x00160016	/*  SMC_CYCLE */
#define SMC_CTRL0_VAL 0x00161003	/*  SMC_MODE */

/* setup CS3 (NAND Flash) - 16-bit */
#define SMC_SETUP3_VAL 0x03030303	/*  SMC_SETUP */
#define SMC_PULSE3_VAL 0x04040404	/*  SMC_PULSE */
#define SMC_CYCLE3_VAL 0x00080008	/*  SMC_CYCLE */
#define SMC_CTRL3_VAL  0x00161003	/*  SMC_MODE */

/* NAND FLash: configure PIOs in periph mode */
#define PIOC_ASR_VAL 3			/*  PIOC->ASR <- PC0 | PC1 */
#define PIOC_BSR_VAL 0			/*  PIOC->BSR */
#define PIOC_PDR_VAL2 3			/*  PIOC->PDR <- PC0 | PC1 */
#define PIOC_PER_VAL 0x4000
#define PIOC_OER_VAL 0x4000		/*  PIOC->PER <- PC14 */
#define PIOC_SODR_VAL 0x4000		/*  PIOC->SODR, set PC14 to '1' */

#define RSTC_RMR_VAL 0xA5000001		/* user reset enable */

_TEXT_BASE:
	.word	TEXT_BASE

.globl lowlevel_init
lowlevel_init:

	mov	r5, pc		// r5 = POS1 + 4 current
POS1:
	ldr	r0, =POS1	// r0 = POS1 compile
	ldr	r2, _TEXT_BASE
	sub	r0, r0, r2	// r0 = POS1-_TEXT_BASE (POS1 relative)
	sub	r5, r5, r0	// r0 = TEXT_BASE-1
	sub	r5, r5, #4	// r1 = text base - current

	/* memory control configuration 1 */
	ldr	r0, =SMRDATA
	ldr	r2, =SMRDATA1
	ldr	r1, _TEXT_BASE
	sub	r0, r0, r1
	sub	r2, r2, r1
	add	r0, r0, r5
	add	r2, r2, r5
0:
	/* the address */
	ldr	r1, [r0], #4
	/* the value */
	ldr	r3, [r0], #4
	str	r3, [r1]
	cmp	r2, r0
	bne	0b

/*-----------------------------------------------------------------------------
;PMC Init Step 1.
;------------------------------------------------------------------------------
;- Enable the Main Oscillator
;----------------------------------------------------------------------------*/
	ldr     r1, =AT91C_BASE_PMC
/* Main oscillator Enable register PMC_MOR: */
/* Enable main oscillator, OSCOUNT = 0xFF */
	ldr 	r0, =0x0000FF01
	str     r0, [r1, #PMC_MOR]

/* Reading the PMC Status register to detect when the */
/* Main Oscillator is enabled */
	mov     r4, #AT91C_PMC_MOSCS
MOSCS_Loop:
	ldr     r3, [r1, #PMC_SR]
	and     r3, r4, r3
	cmp     r3, #AT91C_PMC_MOSCS
	bne     MOSCS_Loop

/*-----------------------------------------------------------------------------
;PMC Init Step 2.
;------------------------------------------------------------------------------
;- Setup PLLA
;----------------------------------------------------------------------------*/
	ldr     r1, = AT91C_BASE_PMC
/* (18.432MHz/1)*13 = 239 MHz */
	ldr 	r0, =PLLAR_VAL
	str     r0, [r1, #PMC_PLLAR]

/* Reading the PMC Status register to detect */
/* when the PLLA is locked */
	mov     r4, #AT91C_PMC_LOCKA
MOSCS_Loop1:
	ldr     r3, [r1, #PMC_SR]
	and     r3, r4, r3
	cmp     r3, #AT91C_PMC_LOCKA
	bne     MOSCS_Loop1


/*-----------------------------------------------------------------------------
;PMC Init Step 3.
;------------------------------------------------------------------------------
;- Switch on the Main Oscillator 18.432 MHz
;----------------------------------------------------------------------------*/
	ldr     r1, =AT91C_BASE_PMC
Init_MCKR:

/* -Master Clock Controller register PMC_MCKR */
/*	ldr     r0, = AT91C_PMC_CSS_MAIN_CLK:OR:AT91C_PMC_PRES_CLK */
	ldr     r0, =0x102
	str     r0, [r1, #PMC_MCKR]

/* Reading the PMC Status register to detect */
/* when the Master clock is ready */
	mov     r4, #AT91C_PMC_MCKRDY
MCKRDY_Loop:
	ldr     r3, [r1, #PMC_SR]
	and     r3, r4, r3
	cmp     r3, #AT91C_PMC_MCKRDY
	bne     MCKRDY_Loop

/*-----------------------------------------------------------------------------
;PMC Init Step 4.
;------------------------------------------------------------------------------
;- Setup PLLB
;----------------------------------------------------------------------------*/
	ldr     r1, = AT91C_BASE_PMC
/* 48.054857 MHz =18432000*72/14/2 for USB) */
	ldr 	r0, =PLLBR_VAL
	str     r0, [r1, #PMC_PLLBR]

/* Reading the PMC Status register to detect */
/* when the PLLB is locked */
	mov     r4, #AT91C_PMC_LOCKB
MOSCS_Loop2:
	ldr     r3, [r1, #PMC_SR]
	and     r3, r4, r3
	cmp     r3, #AT91C_PMC_LOCKB
	bne     MOSCS_Loop2



	/* memory control configuration 2 */
	ldr	r0, =SMRDATA1
	ldr	r2, =SMRDATA2
	ldr	r1, _TEXT_BASE
	sub	r0, r0, r1
	sub	r2, r2, r1
	add	r0, r0, r5
	add	r2, r2, r5

2:
	/* the address */
	ldr	r1, [r0], #4
	/* the value */
	ldr	r3, [r0], #4
	str	r3, [r1]
	cmp	r2, r0
	bne	2b

	/* everything is fine now */
	mov	pc, lr

	.ltorg

SMRDATA:
	.word AT91C_WDTC_WDMR
	.word WDTC_WDMR_VAL
	.word AT91C_PIOC_PDR
	.word PIOC_PDR_VAL1
	.word AT91C_PIOC_PPUDR
	.word PIOC_PPUDR_VAL
	.word AT91C_MATRIX_EBICSA
	.word MATRIX_EBICSA_VAL

	.word AT91C_SMC_SETUP0
	.word SMC_SETUP0_VAL
	.word AT91C_SMC_PULSE0
	.word SMC_PULSE0_VAL
	.word AT91C_SMC_CYCLE0
	.word SMC_CYCLE0_VAL
	.word AT91C_SMC_CTRL0
	.word SMC_CTRL0_VAL
	.word AT91C_SMC_SETUP3
	.word SMC_SETUP3_VAL
	.word AT91C_SMC_PULSE3
	.word SMC_PULSE3_VAL
	.word AT91C_SMC_CYCLE3
	.word SMC_CYCLE3_VAL
	.word AT91C_SMC_CTRL3
	.word SMC_CTRL3_VAL

	.word AT91C_PIOC_ASR
	.word PIOC_ASR_VAL
	.word AT91C_PIOC_BSR
	.word PIOC_BSR_VAL
	.word AT91C_PIOC_PDR
	.word PIOC_PDR_VAL2
	.word AT91C_PIOC_PER
	.word PIOC_PER_VAL
	.word AT91C_PIOC_OER
	.word PIOC_OER_VAL
	.word AT91C_PIOC_SODR
	.word PIOC_SODR_VAL

SMRDATA1:
	.word AT91C_SDRAMC_MR
	.word SDRC_MR_VAL1
	.word AT91C_SDRAMC_TR
	.word SDRC_TR_VAL1
	.word AT91C_SDRAMC_CR
	.word SDRC_CR_VAL
	.word AT91C_SDRAMC_MDR
	.word SDRC_MDR_VAL
	.word AT91C_SDRAMC_MR
	.word SDRC_MR_VAL2
	.word SDRAM
	.word SDRAM_VAL1
	.word AT91C_SDRAMC_MR
	.word SDRC_MR_VAL3
	.word SDRAM
	.word SDRAM_VAL2
	.word SDRAM
	.word SDRAM_VAL3
	.word SDRAM
	.word SDRAM_VAL4
	.word SDRAM
	.word SDRAM_VAL5
	.word SDRAM
	.word SDRAM_VAL6
	.word SDRAM
	.word SDRAM_VAL7
	.word SDRAM
	.word SDRAM_VAL8
	.word SDRAM
	.word SDRAM_VAL9
	.word AT91C_SDRAMC_MR
	.word SDRC_MR_VAL4
	.word SDRAM
	.word SDRAM_VAL10
	.word AT91C_SDRAMC_MR
	.word SDRC_MR_VAL5
	.word SDRAM
	.word SDRAM_VAL11
	.word AT91C_SDRAMC_TR
	.word SDRC_TR_VAL2
	.word SDRAM
	.word SDRAM_VAL12
	.word AT91C_RSTC_RMR
	.word RSTC_RMR_VAL

SMRDATA2:
	.word 0

#endif /* CONFIG_SKIP_LOWLEVEL_INIT */
