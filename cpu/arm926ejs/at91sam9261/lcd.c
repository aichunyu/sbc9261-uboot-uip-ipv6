/*
 * AT91SAM9261 LCD Controller
 *
 * (C) Copyright 2001-2002
 * Wolfgang Denk, DENX Software Engineering -- wd@denx.de
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

/************************************************************************/
/* ** HEADER FILES							*/
/************************************************************************/

#include <config.h>
#include <common.h>
#include <version.h>
#include <stdarg.h>
#include <linux/types.h>
#include <devices.h>

#undef  CONFIG_LCD_LOGO
#include <lcd.h>
#include <asm/arch/hardware.h>

#include "lcd_lut.h"


#ifdef CONFIG_LCD

#define LCD_BPP  LCD_COLOR8

/* #define DEBUG */
#define FB_SYNC_HOR_HIGH_ACT	1	/* horizontal sync high active	*/
#define FB_SYNC_VERT_HIGH_ACT	2	/* vertical sync high active	*/

/* More or less configurable parameters for LCDC controller*/
#define SIDSAFB_FIFO_SIZE		512
#define SIDSAFB_DMA_BURST_LEN		16
#define SIDSAFB_CRST_VAL                0xDA // 0xc8


AT91PS_SYS  AT91_SYS = (AT91PS_SYS)AT91C_BASE_SYS;

/* 240x320x16 @ 61 Hz */
vidinfo_t panel_info = {
	vl_col:		240,
	vl_row:		320,
	vl_width:	64,
	vl_height:	86,
	vl_pixclock:    4965000,
	vl_hsp:		FB_SYNC_HOR_HIGH_ACT,
	vl_vsp:		FB_SYNC_VERT_HIGH_ACT,
	vl_bpix:	3,
	vl_tft:		1,
	/* Horizontal control Timing */
	vl_hpw:		5,
	vl_blw:		1,
	vl_elw:		33,
	/* Vertical control Timing */
	vl_vpw:		1,
	vl_bfw:		1,
	vl_efw:		0,
};




/*----------------------------------------------------------------------*/
void lcd_setcolreg (ushort regno, ushort red, ushort green, ushort blue);
void lcd_ctrl_init (void *lcdbase);
void lcd_enable	(void);

//static void lcd_init_lut(void);


int lcd_line_length;
int lcd_color_fg;
int lcd_color_bg;

void *lcd_base;			/* Start of framebuffer memory	*/
void *lcd_console_address;		/* Start of console buffer	*/

short console_col;
short console_row;



/************************************************************************/

static void AT91F_LCDC_TFT_CfgPIO (void)
{
  AT91_SYS->PIOB_PDR = (AT91C_PB1_LCDHSYNC | AT91C_PB2_LCDDOTCK | AT91C_PB3_LCDDEN | AT91C_PB4_LCDCC |
			AT91C_PB7_LCDD2 | AT91C_PB8_LCDD3 | AT91C_PB9_LCDD4 |
			AT91C_PB10_LCDD5 | AT91C_PB11_LCDD6 | AT91C_PB12_LCDD7 |
			AT91C_PB15_LCDD10 | AT91C_PB16_LCDD11 | AT91C_PB17_LCDD12 |
			AT91C_PB18_LCDD13 | AT91C_PB19_LCDD14 | AT91C_PB20_LCDD15 |
			AT91C_PB23_LCDD18 | AT91C_PB24_LCDD19 | AT91C_PB25_LCDD20 |
			AT91C_PB26_LCDD21 | AT91C_PB27_LCDD22 | AT91C_PB28_LCDD23);

  AT91_SYS->PIOB_BSR = (AT91C_PB23_LCDD18 | AT91C_PB24_LCDD19 | AT91C_PB25_LCDD20 |
			AT91C_PB26_LCDD21 | AT91C_PB27_LCDD22 | AT91C_PB28_LCDD23);

  /* Configure PA22 in pio to enable LCD */
  AT91_SYS->PIOA_PER = AT91C_PIO_PA22;
  AT91_SYS->PIOA_OER = AT91C_PIO_PA22;

  AT91_SYS->PIOA_CODR = AT91C_PIO_PA22;
}

#if 0
static void lcd_init_lut(void)
{
	unsigned int i;
	for(i =0; i <256; i++) {
		panel_info.controller.lcdc->LCDC_LUT_ENTRY[i] =
		   ((rgbPalette[i].red) >> 3 |
		   ((rgbPalette[i].green & 0xf8) << 2) |
		   ((rgbPalette[i].blue & 0xf8) << 7));
	}
}
#endif

void lcd_setcolreg (ushort regno, ushort red,
		    ushort green, ushort blue)
{
  panel_info.controller.lcdc->LCDC_LUT_ENTRY[regno] = ((red >> 3) |
						       ((green & 0xf8) << 2) |
						       ((blue & 0xf8) << 7));
}


void lcd_ctrl_init (void *lcdbase)
{

	unsigned long value;

	AT91F_LCDC_TFT_CfgPIO();

	/* Enable HCLOCK in PMC */
	AT91_SYS->PMC_SCER = AT91C_PMC_HCK1;

	/* Init controller field in panel_info */
	panel_info.controller.lcdc = (AT91PS_LCDC) AT91C_BASE_LCDC;
	panel_info.controller.frame_buffer = (unsigned long) lcdbase;

	/* Turn off the LCD controller and the DMA controller */
	panel_info.controller.lcdc->LCDC_PWRCON = 0x0C;
	panel_info.controller.lcdc->LCDC_DMACON = 0;

	/* Reset LCDC DMA */
	panel_info.controller.lcdc->LCDC_DMACON = AT91C_LCDC_DMARST;

	/* ...set frame size and burst length = 8 words (?) */
	value = ((unsigned int)panel_info.vl_row * (unsigned int)panel_info.vl_col * (unsigned int)NBITS(panel_info.vl_bpix)) / 32;
	value |= ((512 - 1) << 24);
	panel_info.controller.lcdc->LCDC_FRMCFG = value;

	/* Set pixel clock */
	value = AT91C_MASTER_CLOCK / panel_info.vl_pixclock;

	if (AT91C_MASTER_CLOCK % panel_info.vl_pixclock)
	  value++;

	value = (value / 2) - 1;

	if (!value) {
		panel_info.controller.lcdc->LCDC_LCDCON1 = AT91C_LCDC_BYPASS;
	} else
		panel_info.controller.lcdc->LCDC_LCDCON1 = value << 12;

	/* Initialize control register 2 */
	if (panel_info.vl_tft)
	  value = ( AT91C_LCDC_MEMOR_LITTLEIND | AT91C_LCDC_DISTYPE_TFT | AT91C_LCDC_CLKMOD);
	else
	  value = ( AT91C_LCDC_MEMOR_LITTLEIND | AT91C_LCDC_CLKMOD);

	if (!((unsigned int)panel_info.vl_hsp & FB_SYNC_HOR_HIGH_ACT))
		value |= 1 << 10;	/* INVLINE */
	if (!((unsigned int)panel_info.vl_vsp & FB_SYNC_VERT_HIGH_ACT))
		value |= 1 << 9;	/* INVFRAME */

	value |= (unsigned int)(panel_info.vl_bpix << 5);

	/*
	switch (TFT_Panel_Info.bpp) {
		case 1:	value |= 0 << 5; break;
		case 2: value |= 1 << 5; break;
		case 4: value |= 2 << 5; break;
		case 8:
			value |= 3 << 5;
			lcd_init_lut();
		break;
		case 16: value |= 4 << 5; break;
		case 24: value |= 5 << 5; break;
		case 32: value |= 6 << 5; break;
		default : break;
	}
	*/

	panel_info.controller.lcdc->LCDC_LCDCON2 = value;

	/* Vertical timing */
	value = (unsigned int)((panel_info.vl_vpw - 1) << 16);
	value |= (unsigned int)(panel_info.vl_bfw << 8);
	value |= (unsigned int)panel_info.vl_efw;
	panel_info.controller.lcdc->LCDC_TIM1 = value;

	/* Horizontal timing */
	value = (unsigned int)((panel_info.vl_elw - 1) << 21);
	value |= (unsigned int)((panel_info.vl_hpw - 1) << 8);
	value |= (unsigned int)(panel_info.vl_blw - 1);

	panel_info.controller.lcdc->LCDC_TIM2 = value;

	value = (unsigned int)((panel_info.vl_col - 1) << 21);
	value |= (unsigned int)(panel_info.vl_row - 1);

	panel_info.controller.lcdc->LCDC_LCDFRCFG = value;

	/* FIFO Threshold: Use formula from data sheet */
	value = SIDSAFB_FIFO_SIZE - (2 * SIDSAFB_DMA_BURST_LEN + 3);
	panel_info.controller.lcdc->LCDC_FIFO = value;

	/* Toggle LCD_MODE every frame */
	value = 0;
	panel_info.controller.lcdc->LCDC_MVAL = value;

	/* Disable all interrupts */
	panel_info.controller.lcdc->LCDC_IDR = ~0UL;
	/* Set contrast */
	value = AT91C_LCDC_PS_DIVIDEDBYEIGHT | AT91C_LCDC_POL_POSITIVEPULSE | AT91C_LCDC_ENA_PWMGEMENABLED;
	panel_info.controller.lcdc->LCDC_CTRSTCON = value;
	panel_info.controller.lcdc->LCDC_CTRSTVAL = SIDSAFB_CRST_VAL;

	panel_info.controller.lcdc->LCDC_BA1 = (unsigned int)lcdbase;
	panel_info.controller.lcdc->LCDC_FRMCFG = (15 << 24) + ((unsigned int)panel_info.vl_col * (unsigned int)panel_info.vl_row * (unsigned int)NBITS(panel_info.vl_bpix)) / 32;
	panel_info.controller.lcdc->LCDC_DMACON    = AT91C_LCDC_DMAEN;
	panel_info.controller.lcdc->LCDC_PWRCON    = AT91C_LCDC_PWR | 0x0c;
}


/*----------------------------------------------------------------------*/
void lcd_enable (void)
{
}

#if 0
/*----------------------------------------------------------------------*/
static void lcd_disable (void)
{
}
#endif

/*----------------------------------------------------------------------*/

ulong calc_fbsize (void)
{
	ulong size;
	int line_length = ((unsigned int)panel_info.vl_col * (unsigned int)NBITS(panel_info.vl_bpix)) / 8;

	size = line_length * (unsigned int)panel_info.vl_row;
	size += PAGE_SIZE;

	return size;
}

#endif /* CONFIG_LCD */
