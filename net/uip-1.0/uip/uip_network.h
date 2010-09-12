/*
 * (C) Copyright 2010
 * Srinivasan Jayarajan, <srinivasan.jayarajan at gmail.com>
 *  - IPv6 ping support for u-boot 
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
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston,
 * MA 02110-1335 USA
 *
 * For more information on the GPL, please go to:
 * http://www.gnu.org/copyleft/gpl.html
 */

#ifndef __UIP_NETWORK_H__
#define __UIP_NETWORK_H__
#include <uip.h>
enum {
	PING6_SUCCESS = 1,
	PING6_REPLY_WAIT
};

extern uip_ipaddr_t ping6_addr;
extern volatile int ping6_status;

void uip_network_init(void);
void uip_network_loop(void);
int uip_network_addr_set(void);
int ping6(uip_ipaddr_t *ping_addr);
int tftp6_get(char *filename);
void uip_lladdr_set(void);
int uip_ipv6addr_netwk_cmp(uip_ipaddr_t *ipaddr1, uip_ipaddr_t *ipaddr2, int prefix_len);
#endif /* __UIP_NETWORK_H__ */
