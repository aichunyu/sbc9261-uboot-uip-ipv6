/*
 * (C) Copyright 2002-2006
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
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

/*
 * To match the U-Boot user interface on ARM platforms to the U-Boot
 * standard (as on PPC platforms), some messages with debug character
 * are removed from the default U-Boot build.
 *
 * Define DEBUG here if you want additional info as shown below
 * printed upon startup:
 *
 * U-Boot code: 00F00000 -> 00F3C774  BSS: -> 00FC3274
 * IRQ Stack: 00ebff7c
 * FIQ Stack: 00ebef7c
 */

#include <common.h>
#include <command.h>
#include <malloc.h>
#include <devices.h>
#include <version.h>
#include <net.h>

#ifdef CONFIG_DRIVER_SMC91111
#include "../drivers/smc91111.h"
#endif
#ifdef CONFIG_DRIVER_LAN91C96
#include "../drivers/lan91c96.h"
#endif
#include "../cpu/arm926ejs/at91sam9261/lib_twi.h"

DECLARE_GLOBAL_DATA_PTR;

#if (CONFIG_COMMANDS & CFG_CMD_NAND)
void nand_init (void);
#endif

ulong monitor_flash_len;

#ifdef CONFIG_HAS_DATAFLASH
extern int  AT91F_DataflashInit(void);
extern void dataflash_print_info(void);
#endif

#ifndef CONFIG_IDENT_STRING
#define CONFIG_IDENT_STRING ""
#endif

const char version_string[] =
	U_BOOT_VERSION" (" __DATE__ " - " __TIME__ ")"CONFIG_IDENT_STRING;

#ifdef CONFIG_DRIVER_CS8900
extern void cs8900_get_enetaddr (uchar * addr);
#endif

#ifdef CONFIG_DRIVER_RTL8019
extern void rtl8019_get_enetaddr (uchar * addr);
#endif

/*
 * Begin and End of memory area for malloc(), and current "brk"
 */
static ulong mem_malloc_start = 0;
static ulong mem_malloc_end = 0;
static ulong mem_malloc_brk = 0;

static
void mem_malloc_init (ulong dest_addr)
{
	mem_malloc_start = dest_addr;
	mem_malloc_end = dest_addr + CFG_MALLOC_LEN;
	mem_malloc_brk = mem_malloc_start;

	memset ((void *) mem_malloc_start, 0,
			mem_malloc_end - mem_malloc_start);
}

void *sbrk (ptrdiff_t increment)
{
	ulong old = mem_malloc_brk;
	ulong new = old + increment;

	if ((new < mem_malloc_start) || (new > mem_malloc_end)) {
		return (NULL);
	}
	mem_malloc_brk = new;

	return ((void *) old);
}

/************************************************************************
 * Init Utilities							*
 ************************************************************************
 * Some of this code should be moved into the core functions,
 * or dropped completely,
 * but let's get it working (again) first...
 */

static int init_baudrate (void)
{
	char tmp[64];	/* long enough for environment variables */
	int i = getenv_r ("baudrate", tmp, sizeof (tmp));
	gd->bd->bi_baudrate = gd->baudrate = (i > 0)
			? (int) simple_strtoul (tmp, NULL, 10)
			: CONFIG_BAUDRATE;

	return (0);
}

static int display_banner (void)
{
	printf ("\n\n%s\n\n", version_string);
	debug ("U-Boot code: %08lX -> %08lX  BSS: -> %08lX\n",
	       _armboot_start, _bss_start, _bss_end);
#ifdef CONFIG_MODEM_SUPPORT
	debug ("Modem Support enabled\n");
#endif
#ifdef CONFIG_USE_IRQ
	debug ("IRQ Stack: %08lx\n", IRQ_STACK_START);
	debug ("FIQ Stack: %08lx\n", FIQ_STACK_START);
#endif

	return (0);
}

/*
 * WARNING: this code looks "cleaner" than the PowerPC version, but
 * has the disadvantage that you either get nothing, or everything.
 * On PowerPC, you might see "DRAM: " before the system hangs - which
 * gives a simple yet clear indication which part of the
 * initialization if failing.
 */
static int display_dram_config (void)
{
	int i;

#ifdef DEBUG
	puts ("RAM Configuration:\n");

	for(i=0; i<CONFIG_NR_DRAM_BANKS; i++) {
		printf ("Bank #%d: %08lx ", i, gd->bd->bi_dram[i].start);
		print_size (gd->bd->bi_dram[i].size, "\n");
	}
#else
	ulong size = 0;

	for (i=0; i<CONFIG_NR_DRAM_BANKS; i++) {
		size += gd->bd->bi_dram[i].size;
	}
	puts("DRAM:  ");
	print_size(size, "\n");
#endif

	return (0);
}

#ifndef CFG_NO_FLASH
static void display_flash_config (ulong size)
{
	puts ("Flash: ");
	print_size (size, "\n");
}
#endif /* CFG_NO_FLASH */


/*
 * Breathe some life into the board...
 *
 * Initialize a serial port as console, and carry out some hardware
 * tests.
 *
 * The first part of initialization is running from Flash memory;
 * its main purpose is to initialize the RAM so that we
 * can relocate the monitor code to RAM.
 */

/*
 * All attempts to come up with a "common" initialization sequence
 * that works for all boards and architectures failed: some of the
 * requirements are just _too_ different. To get rid of the resulting
 * mess of board dependent #ifdef'ed code we now make the whole
 * initialization sequence configurable to the user.
 *
 * The requirements for any new initalization function is simple: it
 * receives a pointer to the "global data" structure as it's only
 * argument, and returns an integer return code, where 0 means
 * "continue" and != 0 means "fatal error, hang the system".
 */
typedef int (init_fnc_t) (void);

int print_cpuinfo (void); /* test-only */

init_fnc_t *init_sequence[] = {
	cpu_init,		/* basic cpu dependent setup */
	board_init,		/* basic board dependent setup */
	interrupt_init,		/* set up exceptions */
	env_init,		/* initialize environment */
	init_baudrate,		/* initialze baudrate settings */
	serial_init,		/* serial communications setup */
	console_init_f,		/* stage 1 init of console */
	display_banner,		/* say that we are here */
#if defined(CONFIG_DISPLAY_CPUINFO)
	print_cpuinfo,		/* display cpu info (and speed) */
#endif
#if defined(CONFIG_DISPLAY_BOARDINFO)
	checkboard,		/* display board info */
#endif
	dram_init,		/* configure available RAM banks */
	display_dram_config,
	NULL,
};

char ch7025_map[][2]  =  {
#if 0
{ 0x02, 0x01 },
{ 0x02, 0x03 },
{ 0x03, 0x00 },
{ 0x04, 0x01 },			 //power down
{ 0x7D, 0x01 },

{ 0x08, 0x08 },
{ 0x0C, 0x82 },
{ 0x0D, 0x08 },
{ 0x0F, 0x08 },
{ 0x10, 0xF0 },
{ 0x11, 0x11 },
{ 0x13, 0x0B },
{ 0x14, 0x05 },
{ 0x15, 0x09 },
{ 0x16, 0x40 },
{ 0x17, 0x47 },
{ 0x19, 0x02 },
{ 0x1A, 0x01 },
{ 0x1B, 0x23 },
{ 0x1C, 0x20 },
{ 0x1D, 0x20 },
{ 0x1F, 0x25 },
{ 0x20, 0x80 },
{ 0x21, 0x12 },
{ 0x22, 0x58 },
{ 0x23, 0x74 },
{ 0x25, 0x0A },
{ 0x26, 0x04 },
{ 0x37, 0x20 },
{ 0x39, 0x20 },
{ 0x3B, 0x20 },
{ 0x41, 0xA2 },
{ 0x4D, 0x03 },
{ 0x4E, 0x0F },
{ 0x4F, 0xC0 },
{ 0x50, 0xFC },
{ 0x51, 0x53 },
{ 0x52, 0x12 },
{ 0x53, 0x13 },
{ 0x55, 0xE5 },
{ 0x77, 0x03 },
{ 0x7D, 0x62 },
	
{ 0x06, 0x71 },
{ 0x06, 0x70 },
//{ 0x02, 0x02 },
//{ 0x02, 0x03 },
{ 0x04, 0x00 },				//power up
#elif 0 


{ 0x02, 0x01 },
{ 0x02, 0x03 },
{ 0x03, 0x00 },
{ 0x04, 0x01 },			 //power down
{ 0x7D, 0x01 },

{ 0x07, 0x3F },
{ 0x08, 0x08 },
{ 0x0C, 0x82 },
{ 0x0D, 0x08 },
{ 0x11, 0x74 },
{ 0x13, 0x1E },
{ 0x14, 0x16 },
{ 0x15, 0x00 },
{ 0x17, 0xFF },
{ 0x19, 0x0B },
{ 0x1A, 0x04 },
{ 0x1B, 0x23 },
{ 0x1C, 0x20 },
{ 0x1D, 0x20 },
{ 0x1F, 0x25 },
{ 0x20, 0x80 },
{ 0x21, 0x12 },
{ 0x22, 0x58 },
{ 0x23, 0x74 },
{ 0x25, 0x0A },
{ 0x26, 0x04 },
{ 0x37, 0x20 },
{ 0x39, 0x20 },
{ 0x3B, 0x20 },
{ 0x41, 0xA2 },
{ 0x4D, 0x03 },
{ 0x4E, 0x0F },
{ 0x4F, 0xC0 },
{ 0x50, 0xFC },
{ 0x51, 0x53 },
{ 0x52, 0x12 },
{ 0x53, 0x13 },
{ 0x55, 0xE5 },
{ 0x77, 0x03 },
{ 0x7D, 0x62 },

{ 0x06, 0x71 },
{ 0x06, 0x70 },
//{ 0x02, 0x02 },
//{ 0x02, 0x03 },
{ 0x04, 0x00 },				//power up

#else

{ 0x02, 0x01 },
{ 0x02, 0x03 },
{ 0x03, 0x00 },
{ 0x04, 0x01 },			 //power down
{ 0x7D, 0x01 },

{ 0x07, 0x3F },
{ 0x08, 0x08 },
{ 0x0C, 0xD2 },
{ 0x0D, 0x08 },
{ 0x11, 0x74 },
{ 0x13, 0x1E },
{ 0x14, 0x16 },
{ 0x15, 0x00 },
{ 0x17, 0xFF },
{ 0x19, 0x0B },
{ 0x1A, 0x04 },
{ 0x1B, 0x23 },
{ 0x1C, 0x20 },
{ 0x1D, 0x20 },
{ 0x1F, 0x25 },
{ 0x20, 0x80 },
{ 0x21, 0x12 },
{ 0x22, 0x58 },
{ 0x23, 0x74 },
{ 0x25, 0x0A },
{ 0x26, 0x04 },
{ 0x37, 0x20 },
{ 0x39, 0x20 },
{ 0x3B, 0x20 },
{ 0x41, 0xA2 },
{ 0x4D, 0x03 },
{ 0x4E, 0x0F },
{ 0x4F, 0xC0 },
{ 0x50, 0xFC },
{ 0x51, 0x53 },
{ 0x52, 0x12 },
{ 0x53, 0x13 },
{ 0x55, 0xE5 },
{ 0x77, 0x03 },
{ 0x7D, 0x62 },


{ 0x06, 0x71 },
{ 0x06, 0x70 },
//{ 0x02, 0x02 },
//{ 0x02, 0x03 },
{ 0x04, 0x00 },				//power up

#endif

};

#define CH7026_SLAVE_ADDRESS	 ( ( 0x76 ) << 16 )
#define IS7X2_IN_ADDR_NUM(x)	( ( (x) & 0x03 ) << 8 )

void start_armboot (void)
{
	init_fnc_t **init_fnc_ptr;
	char *s;
#if !defined(CFG_NO_FLASH) || defined(CONFIG_LCD)
	ulong size;
#endif
#if defined(CONFIG_VFD) || (defined(CONFIG_LCD) && !defined(CONFIG_MACH_PM9261))
	unsigned long addr;
#endif

	int i,sizeoof;
	sizeoof = sizeof(ch7025_map)/ (2*sizeof(unsigned char));

	/* Pointer is writable since we allocated a register for it */
	gd = (gd_t*)(_armboot_start - CFG_MALLOC_LEN - sizeof(gd_t));
	/* compiler optimization barrier needed for GCC >= 3.4 */
	__asm__ __volatile__("": : :"memory");

	memset ((void*)gd, 0, sizeof (gd_t));
	gd->bd = (bd_t*)((char*)gd - sizeof(bd_t));
	memset (gd->bd, 0, sizeof (bd_t));

	monitor_flash_len = _bss_start - _armboot_start;

	for (init_fnc_ptr = init_sequence; *init_fnc_ptr; ++init_fnc_ptr) {
		if ((*init_fnc_ptr)() != 0) {
			hang ();
		}
	}

#ifndef CFG_NO_FLASH
	/* configure available FLASH banks */
	size = flash_init ();
	display_flash_config (size);
#endif /* CFG_NO_FLASH */

#ifdef CONFIG_VFD
#	ifndef PAGE_SIZE
#	  define PAGE_SIZE 4096
#	endif
	/*
	 * reserve memory for VFD display (always full pages)
	 */
	/* bss_end is defined in the board-specific linker script */
	addr = (_bss_end + (PAGE_SIZE - 1)) & ~(PAGE_SIZE - 1);
	size = vfd_setmem (addr);
	gd->fb_base = addr;
#endif /* CONFIG_VFD */

#ifndef CONFIG_MACH_PM9261
#ifdef CONFIG_LCD
#	ifndef PAGE_SIZE
#	  define PAGE_SIZE 4096
#	endif
	/*
	 * reserve memory for LCD display (always full pages)
	 */
	/* bss_end is defined in the board-specific linker script */
	addr = (_bss_end + (PAGE_SIZE - 1)) & ~(PAGE_SIZE - 1);
	size = lcd_setmem (addr);
	gd->fb_base = addr;
#endif /* CONFIG_LCD */
#endif /* ! CONFIG_MACH_PM9261 */

	/* armboot_start is defined in the board-specific linker script */
	mem_malloc_init (_armboot_start - CFG_MALLOC_LEN);

#if (CONFIG_COMMANDS & CFG_CMD_NAND)
	puts ("NAND:  ");
	nand_init();		/* go init the NAND */
#endif

#ifdef CONFIG_HAS_DATAFLASH
	AT91F_DataflashInit();
	dataflash_print_info();
#endif

	/* initialize environment */
	env_relocate ();

#ifdef CONFIG_VFD
	/* must do this after the framebuffer is allocated */
	drv_vfd_init();
#endif /* CONFIG_VFD */

	/* IP Address */
	gd->bd->bi_ip_addr = getenv_IPaddr ("ipaddr");

	/* MAC Address */
	{
		int i;
		ulong reg;
		char *s, *e;
		char tmp[64];

		i = getenv_r ("ethaddr", tmp, sizeof (tmp));
		s = (i > 0) ? tmp : NULL;

		for (reg = 0; reg < 6; ++reg) {
			gd->bd->bi_enetaddr[reg] = s ? simple_strtoul (s, &e, 16) : 0;
			if (s)
				s = (*e) ? e + 1 : e;
		}

#ifdef CONFIG_HAS_ETH1
		i = getenv_r ("eth1addr", tmp, sizeof (tmp));
		s = (i > 0) ? tmp : NULL;

		for (reg = 0; reg < 6; ++reg) {
			gd->bd->bi_enet1addr[reg] = s ? simple_strtoul (s, &e, 16) : 0;
			if (s)
				s = (*e) ? e + 1 : e;
		}
#endif
	}

	devices_init ();	/* get the devices list going. */

#ifdef CONFIG_CMC_PU2
	load_sernum_ethaddr ();
#endif /* CONFIG_CMC_PU2 */

	jumptable_init ();

	console_init_r ();	/* fully init console as a device */

#if defined(CONFIG_MISC_INIT_R)
	/* miscellaneous platform dependent initialisations */
	misc_init_r ();
#endif

	/* enable exceptions */
	enable_interrupts ();

	/* Perform network card initialisation if necessary */
#ifdef CONFIG_DRIVER_CS8900
	cs8900_get_enetaddr (gd->bd->bi_enetaddr);
#endif

#if defined(CONFIG_DRIVER_SMC91111) || defined (CONFIG_DRIVER_LAN91C96)
	if (getenv ("ethaddr")) {
		smc_set_mac_addr(gd->bd->bi_enetaddr);
	}
#endif /* CONFIG_DRIVER_SMC91111 || CONFIG_DRIVER_LAN91C96 */

	/* Initialize from environment */
	if ((s = getenv ("loadaddr")) != NULL) {
		load_addr = simple_strtoul (s, NULL, 16);
	}
#if (CONFIG_COMMANDS & CFG_CMD_NET)
	if ((s = getenv ("bootfile")) != NULL) {
		copy_filename (BootFile, s, sizeof (BootFile));
	}
#endif	/* CFG_CMD_NET */

#ifdef BOARD_LATE_INIT
	board_late_init ();
#endif
#if (CONFIG_COMMANDS & CFG_CMD_NET)
#if defined(CONFIG_NET_MULTI)
	puts ("Net:   ");
#endif
	eth_initialize(gd->bd);
#endif

	AT91F_TWI_Open();
   	for(i=0; i<sizeoof; i++) {
		AT91F_TWI_WriteSingleIadr(AT91C_BASE_TWI,CH7026_SLAVE_ADDRESS,(int)ch7025_map[i][0], \
  									IS7X2_IN_ADDR_NUM(1), &ch7025_map[i][1]);
	}	


	/* main_loop() can return to retry autoboot, if so just run it again. */
	for (;;) {
		main_loop ();
	}

	/* NOTREACHED - no way out of command loop except booting */
}

void hang (void)
{
	puts ("### ERROR ### Please RESET the board ###\n");
	for (;;);
}

#ifdef CONFIG_MODEM_SUPPORT
static inline void mdm_readline(char *buf, int bufsiz);

/* called from main loop (common/main.c) */
extern void  dbg(const char *fmt, ...);
int mdm_init (void)
{
	char env_str[16];
	char *init_str;
	int i;
	extern char console_buffer[];
	extern void enable_putc(void);
	extern int hwflow_onoff(int);

	enable_putc(); /* enable serial_putc() */

#ifdef CONFIG_HWFLOW
	init_str = getenv("mdm_flow_control");
	if (init_str && (strcmp(init_str, "rts/cts") == 0))
		hwflow_onoff (1);
	else
		hwflow_onoff(-1);
#endif

	for (i = 1;;i++) {
		sprintf(env_str, "mdm_init%d", i);
		if ((init_str = getenv(env_str)) != NULL) {
			serial_puts(init_str);
			serial_puts("\n");
			for(;;) {
				mdm_readline(console_buffer, CFG_CBSIZE);
				dbg("ini%d: [%s]", i, console_buffer);

				if ((strcmp(console_buffer, "OK") == 0) ||
					(strcmp(console_buffer, "ERROR") == 0)) {
					dbg("ini%d: cmd done", i);
					break;
				} else /* in case we are originating call ... */
					if (strncmp(console_buffer, "CONNECT", 7) == 0) {
						dbg("ini%d: connect", i);
						return 0;
					}
			}
		} else
			break; /* no init string - stop modem init */

		udelay(100000);
	}

	udelay(100000);

	/* final stage - wait for connect */
	for(;i > 1;) { /* if 'i' > 1 - wait for connection
				  message from modem */
		mdm_readline(console_buffer, CFG_CBSIZE);
		dbg("ini_f: [%s]", console_buffer);
		if (strncmp(console_buffer, "CONNECT", 7) == 0) {
			dbg("ini_f: connected");
			return 0;
		}
	}

	return 0;
}

/* 'inline' - We have to do it fast */
static inline void mdm_readline(char *buf, int bufsiz)
{
	char c;
	char *p;
	int n;

	n = 0;
	p = buf;
	for(;;) {
		c = serial_getc();

		/*		dbg("(%c)", c); */

		switch(c) {
		case '\r':
			break;
		case '\n':
			*p = '\0';
			return;

		default:
			if(n++ > bufsiz) {
				*p = '\0';
				return; /* sanity check */
			}
			*p = c;
			p++;
			break;
		}
	}
}
#endif	/* CONFIG_MODEM_SUPPORT */
