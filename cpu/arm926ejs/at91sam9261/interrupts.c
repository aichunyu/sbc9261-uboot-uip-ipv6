/*
 * (C) Copyright 2005
 * M. Amine SAYA ATMEL Rousset, France.
 *
 * (C) Copyright 2003
 * Texas Instruments <www.ti.com>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Alex Zuepke <azu@sysgo.de>
 *
 * (C) Copyright 2002-2004
 * Gary Jennejohn, DENX Software Engineering, <gj@denx.de>
 *
 * (C) Copyright 2004
 * Philippe Robin, ARM Ltd. <philippe.robin@arm.com>
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
#include <asm/arch/hardware.h>


/* the number of clocks per CFG_HZ */
#define TIMER_LOAD_VAL 0xfffff

/* macro to read the 20-bit wide AT91SAM9261 PITC value*/
#define READ_RESET_TIMER (p_pitc->PITC_PIVR)
#define READ_TIMER (p_pitc->PITC_PIIR)

ulong get_timer_masked (void);

AT91PS_PITC p_pitc;

static unsigned long long timestamp;
static ulong lastinc;

// nothing really to do with interrupts, just starts up a counter.
int interrupt_init (void) {

	p_pitc = AT91C_BASE_PITC;

	// Enable PITC Clock
	// The clock is already enabled for system controller in boot
	*AT91C_PMC_PCER = 1 << AT91C_ID_SYS;

	// Enable PITC
	p_pitc->PITC_PIMR = AT91C_PITC_PITEN;

	// Load PITC_PIMR with the right timer value
	p_pitc->PITC_PIMR |= TIMER_LOAD_VAL;

	lastinc = 0;
	timestamp = 0;
	return 0;
}


// timer without interrupts


void reset_timer (void) {

	reset_timer_masked ();
}

ulong get_timer (ulong base) {

	return get_timer_masked () - base;
}

void set_timer (ulong t) {

	timestamp = t;
}

void udelay (unsigned long usec) {

	udelay_masked(usec);
}

void reset_timer_masked (void) {

	// reset time
	lastinc = READ_TIMER;
	timestamp = 0;
}

unsigned long long get_timer_raw (void) {

	ulong now = READ_TIMER;

	if (now >= lastinc) {
		// normal mode
		timestamp += now - lastinc;
	} else {
		// we have an overflow ...
		timestamp += now + 0x100000000ull - lastinc;
	}
	lastinc = now;

	return timestamp;
}

ulong get_timer_masked (void) {

	return get_timer_raw () / (AT91C_MASTER_CLOCK / (16 * CFG_HZ));
}

void udelay_masked (unsigned long usec)
{
	unsigned long long tmo;
	unsigned long long endtime;
	unsigned long long now;
	signed long long diff;

	tmo = (AT91C_MASTER_CLOCK / 16) / 1000;
	tmo *= usec;
	tmo /= 1000;

	endtime = get_timer_raw () + tmo;

	do {
		now = get_timer_raw ();
		diff = endtime - now;
	} while (diff >= 0);
}



/*
 * This function is derived from PowerPC code (read timebase as long long).
 * On ARM it just returns the timer value.
 */
unsigned long long get_ticks(void) {

	return get_timer (0);
}

/*
 * This function is derived from PowerPC code (timebase clock frequency).
 * On ARM it returns the number of timer ticks per second.
 */
ulong get_tbclk (void) {
ulong tbclk;

	tbclk = CFG_HZ;
	return tbclk;
}

// Reset the cpu
void reset_cpu (ulong ignored) {


	while (1);
	/* Never reached */
}
