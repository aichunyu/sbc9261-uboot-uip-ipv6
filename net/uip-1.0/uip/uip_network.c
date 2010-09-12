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

#include <common.h>
#include <net.h>
#include <timer.h>
#include <uip_network.h>
#include <uip.h>
#include <uip-neighbor.h>
#include <uip_arp.h>
#include <uip_nd.h>
#include <uip_prefix.h>
#include <uip_util.h>

#define BUF ((struct uip_eth_hdr *)&uip_buf[0])
#define ETHBUF ((struct uip_eth_hdr *)&uip_buf[0])
#define ICMPBUF ((struct uip_icmpip_hdr *)&uip_buf[UIP_LLH_LEN])

struct timer periodic_timer;
struct timer nd_timer;
uip_ipaddr_t ping6_addr;
volatile int ping6_status = 0;
int net_tx(volatile void *, int);
int net_rx(void *packet);
struct timer app_timer;

void dummy_func(void) 
{
}
void dummy_udp_func(void) 
{
}

#ifdef UIP_CONF_IPV6
void uip_network_init(void)
{
	timer_set(&periodic_timer, CLOCK_SECOND / 3); 
	timer_set(&nd_timer, CLOCK_SECOND * 60);

	uip_init();
	uip_network_addr_set();
}

int uip_network_addr_set(void)
{
	int		i;
	char		*s, *e;
	uip_ipaddr_t 	addr;
	int		rc = 0;

	/* set MAC address */
	s = getenv ("ethaddr");
	if (s == NULL) {
		goto end;
	} else {

		for (i = 0; i < 6; i++) {
			uip_ethaddr.addr[i] = s ? simple_strtoul (s, &e, 16) : 0;
			if (s) {
				s = (*e) ? e + 1 : e;
			}
		}
	}

	uip_lladdr_set();
	s = getenv ("ip6addr");
	if (s == NULL)
		goto end; 
	if (!inet_pton6(s, (unsigned char*)&addr)) {
		printf("Illegal IPv6 host address\n");
	}
	uip_sethostaddr(addr);


	s = getenv ("ip6prefixlen");
	if (s == NULL)
		goto end; 
	uip_setprefixlen(simple_strtoul (s, NULL, 10));

	s = getenv ("gatewayip6");
	if (s == NULL)
		goto end; 
	if (!inet_pton6(s, (unsigned char*)&addr)) {
		printf("Illegal IPv6 gateway address\n");
	}
	uip_setdraddr(addr);
	uip_neighbor_init();
	rc = 1;

end:	if (!rc)
		printf("ENV is null\n");
	return rc;
}


void uip_network_loop(void)
{
	int i;

	while(!tstc()) {

		uip_len = net_rx(uip_buf);

		if (uip_len > 0) {
			if (BUF->type == htons(UIP_ETHTYPE_IP6)) {
				uip_input();
				if (uip_len > 0) {
					uip_neighbor_out();
					net_tx(uip_buf, uip_len);
				}
			}

		} else if (timer_expired(&periodic_timer)) {

			timer_reset(&periodic_timer);
			for (i = 0; i < UIP_CONNS; i++) {
				uip_periodic(i);

				if (uip_len > 0) {
					uip_neighbor_out();
					net_tx(uip_buf, uip_len);
				}
			}

#if UIP_UDP
			for (i = 0; i < UIP_UDP_CONNS; i++) {
				uip_udp_periodic(i);

				if (uip_len > 0) {
					uip_neighbor_out();
					net_tx(uip_buf, uip_len);
				}
			}
#endif /* UIP_UDP */
			/* Call the Neighbor timer function every 60 seconds. */
			if (timer_expired(&nd_timer)) {
				timer_reset(&nd_timer);
				uip_neighbor_periodic();
			}
		}

	} /* while */
}
void uip_icmp6_send_echo_req(uip_ipaddr_t *ipaddr, struct uip_neighbor_addr *dest_mac)
{
	uip_appdata = &uip_buf[UIP_TCPIP_HLEN + UIP_LLH_LEN];
	uip_len = UIP_LLH_LEN + UIP_IPH_LEN + 64;
	memset(uip_buf, 0, uip_len);

	if (dest_mac)
		memcpy(ETHBUF->dest.addr, dest_mac->addr.addr, 6);

	memcpy(ETHBUF->src.addr, uip_ethaddr.addr, 6);
	ETHBUF->type = HTONS(UIP_ETHTYPE_IP6);

	ICMPBUF->vtc = 0x60;
	ICMPBUF->len[1] = 64;
	ICMPBUF->proto = UIP_PROTO_ICMP6;
	ICMPBUF->ttl = 64;

	uip_ipaddr_copy(ICMPBUF->srcipaddr, uip_hostaddr);
	uip_ipaddr_copy(ICMPBUF->destipaddr, ipaddr);
	ICMPBUF->type = ICMP6_ECHO;

	/* Calculate checksum */
	ICMPBUF->icmpchksum = ~uip_icmp6chksum();
	UIP_STAT(++uip_stat.icmp.sent);
}

void uip_lladdr_set()
{
	u16_t *p = (u16_t *)&uip_lladdr;
	char temp[64];

	p[0] = HTONS(0xfe80);
	p[1] = 0x0;
	p[2] = 0x0;
	p[3] = 0x0;

	p[4] = HTONS(uip_ethaddr.addr[0] << 8 | uip_ethaddr.addr[1]);
	p[4] ^= HTONS(0x200);
	p[5] = HTONS(uip_ethaddr.addr[2] << 8 | 0x00FF);
	p[6] = HTONS(0xFE00 | uip_ethaddr.addr[3]);
	p[7] = HTONS(uip_ethaddr.addr[4] << 8 | uip_ethaddr.addr[5]);

	inet_ntop6((char*)&uip_lladdr,temp,sizeof(temp));
}

int ping6(uip_ipaddr_t *ipaddr)
{
	struct uip_neighbor_addr *dest_mac;
	struct timer icmp_timer;
	int timeout = 3;
	ping6_status = 0;

	if (!uip_network_addr_set()) {
		printf("Failure setting interface address\n");
		return 0;
	}
	timer_set(&icmp_timer, CLOCK_SECOND * 1);
	ping6_status = PING6_REPLY_WAIT;
	uip_ipaddr_copy(ping6_addr, ipaddr);
	uip_icmp6_send_echo_req(ipaddr, 0);

	do {
		if (ctrlc()) {
#ifndef CONFIG_UIP_STACK_SUPPORT
			eth_halt();
#endif            
			puts ("\nAbort\n");
			return 0;
		}
		if (timer_expired(&icmp_timer)) {
			uip_icmp6_send_echo_req(ipaddr, 0);
			timer_reset(&icmp_timer);
			timeout--;
			putc('.');
		}

		if (uip_len > 0) { 
			uip_neighbor_out();
			net_tx(uip_buf, uip_len);
		}

		uip_len = net_rx(uip_buf);

		if (uip_len > 0) {
			if (BUF->type == htons(UIP_ETHTYPE_IP6)) {
				uip_input();
				if (uip_len > 0) {
					uip_neighbor_out();
					net_tx(uip_buf, uip_len);
				}
			}
		} else if (timer_expired(&periodic_timer)) {
			 timer_reset(&periodic_timer);
			/* Call the Neighbor timer function every 60 seconds. */
			if (timer_expired(&nd_timer)) {
				timer_reset(&nd_timer);
				uip_neighbor_periodic();
			}
		}
		if (ping6_status == PING6_SUCCESS)
			break;

	} while (timeout > 0);

	memset(ping6_addr, 0, sizeof(uip_ipaddr_t));
	dest_mac = uip_neighbor_lookup(*ipaddr);
	putc('\n');

	if (!dest_mac) {
		printf("IPv6 neighbor solicitation timeout\n");
		ping6_status = 0;
		return 0;
	} else if((timeout <= 0) && (ping6_status != PING6_SUCCESS)) {
		ping6_status = 0;
		return 0;
	}
	
	return 1;
}

int uip_ipv6addr_netwk_cmp(uip_ipaddr_t *ipaddr1, uip_ipaddr_t *ipaddr2, int prefix_len)
{
	uip_ipaddr_t temp1;
	uip_ipaddr_t temp2;

	memcpy(&temp1, ipaddr1, sizeof(uip_ip6addr_t));
	memcpy(&temp2, ipaddr2, sizeof(uip_ip6addr_t));

	apply_mask_ipv6(prefix_len, &temp1);
	apply_mask_ipv6(prefix_len, &temp2);

	/* return 1 if both are equal */
	return uip_ipaddr_cmp(&temp1,&temp2);
}
#endif
