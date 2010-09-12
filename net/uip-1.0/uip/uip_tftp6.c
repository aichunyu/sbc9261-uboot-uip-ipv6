/*
 * (C) Copyright 2010
 * Srinivasan Jayarajan, <srinivasan.jayarajan at gmail.com>
 *  - IPv6 tftp support for u-boot 
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

/*
 *	Copyright 1994, 1995, 2000 Neil Russell.
 *	(See License)
 *	Copyright 2000, 2001 DENX Software Engineering, Wolfgang Denk, wd@denx.de
 */

#include <common.h>
#include <net.h>
#include <tftp.h>
#include <timer.h>
#include <uip_network.h>
#include <uip.h>
#include <uip-neighbor.h>
#include <uip_arp.h>
#include <uip_nd.h>
#include <uip_prefix.h>
#include <uip_util.h>

#define UDPBUF ((struct uip_udpip_hdr *)&uip_buf[UIP_LLH_LEN])
#define BUF ((struct uip_eth_hdr *)&uip_buf[0])

#ifdef UIP_CONF_IPV6
static struct uip_udp_conn *tftp6_conn;
extern int	TftpState;
extern ulong    TftpBlock;
extern ulong	TftpLastBlock;
extern ulong	TftpBlockWrap;
extern ulong	TftpBlockWrapOffset;
volatile int tftp6_status = 0;
extern struct timer nd_timer;
extern struct timer periodic_timer;
extern struct timer app_timer;
extern ulong load_addr;
extern ulong NetBootFileXferSize;
char *tftp_filename;

enum {
	TFTP6_RETRY = 5,
	TFTP6_SUCCESS,
	TFTP6_FAILURE,
};

int net_tx(volatile void *, int);
int net_rx(void *packet);
void tftp_send_rrq(void);
void tftp_send_ack(void);

void tftp6_appcall(void)
{
	static int x;
	 if (tftp6_conn && (uip_udp_conn->lport == tftp6_conn->lport)) {
		if (uip_newdata()) {
			u8_t *data = (u8_t *)uip_appdata;
			u16_t opcode = *(u16_t*)data;
			char *nretry;
			int noretry = 0;

			switch (ntohs(opcode)) {
			case TFTP_RRQ:
			case TFTP_WRQ:
			case TFTP_ACK:
				break;
			case TFTP_OACK:
				TftpState = STATE_OACK;
				tftp6_conn->rport = UDPBUF->srcport;
				timer_reset(&app_timer);
				break;
			case TFTP_DATA:
				if (((ntohs(UDPBUF->udplen)) - 12) < 4)
					break;
				timer_reset(&app_timer);

				TftpBlock = ntohs(*((u16_t *)(data + 2)));
				if (TftpBlock == 0) {
					TftpBlockWrap++;
					TftpBlockWrapOffset += TFTP_BLOCK_SIZE * TFTP_SEQUENCE_SIZE;
					printf ("\n\t %lu MB received\n\t ", TftpBlockWrapOffset>>20);
				} else {
					if (((TftpBlock - 1) % 10) == 0) {
						putc ('#');
					} else if ((TftpBlock % (10 * HASHES_PER_LINE)) == 0) {
						puts ("\n\t ");
					}
				}
				if (TftpState == STATE_RRQ || TftpState == STATE_OACK) {
					/* first block received */
					TftpState = STATE_DATA;
					tftp6_conn->rport = UDPBUF->srcport;
					TftpLastBlock = 0;
					TftpBlockWrap = 0;
					TftpBlockWrapOffset = 0;

					if (TftpBlock != 1) {	/* Assertion */
						printf ("\nTFTP error: "
							"First block is not block 1 (%ld)\n"
							"Starting again\n\n",
							TftpBlock);
						//NetStartAgain ();
						break;
					}
				}

				if (TftpBlock == TftpLastBlock) {
					/*
					 *	Same block again; ignore it.
					 */
					break;
				}

				TftpLastBlock = TftpBlock;

				tftp_store_block (TftpBlock - 1, data + 4, ((ntohs(UDPBUF->udplen)) - 12));
				timer_reset(&app_timer);

				if (((ntohs(UDPBUF->udplen)) - 12) < TFTP_BLOCK_SIZE) {
					/*
					 *	We received the whole thing.  Try to
					 *	run it.
					 */
					puts ("\ndone\n");
					tftp6_status = TFTP6_SUCCESS;
					if (NetBootFileXferSize > 0) {
						char buf[10];
						printf("Bytes transferred = %ld (%lx hex)\n",
							NetBootFileXferSize,
							NetBootFileXferSize);
						sprintf(buf, "%lx", NetBootFileXferSize);
						setenv("filesize", buf);

						sprintf(buf, "%lX", (unsigned long)load_addr);
						setenv("fileaddr", buf);
					}
				}
				break;

			case TFTP_ERROR:
				printf ("\nTFTP error: '%s' (%d)\n",
							data + 4, ntohs(*(u16_t *)(data + 2)));

				if ((nretry = getenv ("netretry")) != NULL) {
					noretry = (strcmp (nretry, "no") == 0);
				}
				if (noretry) {
					TftpState = 0;
					tftp6_status = TFTP6_FAILURE;
					break;
				}

				puts ("Starting again\n\n");
				tftp6_status = TFTP6_RETRY;
				timer_reset(&app_timer);
				TftpState = 0;
				break;

			default:
				break;
			}
		}
		switch (TftpState) {
		case STATE_RRQ:	
			if (x%3 == 0) 
				tftp_send_rrq();
			x++;	
			break;
		case STATE_DATA:
		case STATE_OACK:
			tftp_send_ack();
			break;
		default:
			break;
		}
	 }
}

int tftp6_get(char *filename)
{
	uip_ipaddr_t 	addr;
	char *s;

	if (!uip_network_addr_set()) {
		printf("Failure setting interface parameters\n");
		return 0;
	}

	s = getenv ("serverip6");
	if (s == NULL) {
		printf("Server IPv6 address is NULL\n");
		return 0;
	} 

	if (!inet_pton6(s, (unsigned char*)&addr)) {
		printf("Illegal IPv6 server address\n");
	}
	if (tftp6_conn != NULL)
		 uip_udp_remove(tftp6_conn);

	tftp6_conn = uip_udp_new(&addr, HTONS(69));

	if (tftp6_conn == 0){
		printf("Connection failed!\n");
		return 0;
	}
start_gain:	
	printf ("TFTP from server %s", s);
	printf ("; our IPv6 address is %s", getenv ("ip6addr"));

	/* Check if we need to send across this subnet */
	if (!uip_ipv6addr_netwk_cmp(&addr, &uip_hostaddr, uip_prefix_len)) {
		printf("; sending through gateway %s",  getenv ("gatewayip6"));
	}
	putc ('\n');

	printf ("Filename '%s'.\n", filename);
	printf ("Load address: 0x%lx\n", load_addr);

	puts ("Loading: *\b");
	TftpState = STATE_RRQ;
	tftp_filename = filename;
	TftpBlock = 0;
	TftpBlockWrap = 0;
	TftpBlockWrapOffset = 0;
	tftp6_status = 0;
	timer_set(&app_timer, CLOCK_SECOND * 3);

	do {
		uip_len = 0;

		if (ctrlc()) {
#ifndef CONFIG_UIP_STACK_SUPPORT
			eth_halt();
#endif            
			puts ("\nAbort\n");
			return 0;
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
			int i;
			timer_reset(&periodic_timer);
#if UIP_UDP
			for (i = 0; i < UIP_UDP_CONNS; i++) {
				uip_udp_periodic(i);

				if (uip_len > 0) {
					uip_neighbor_out();
					net_tx(uip_buf, uip_len);
				}
			}
#endif		
			/* Call the Neighbor timer function every 60 seconds. */
			if (timer_expired(&nd_timer)) {
				timer_reset(&nd_timer);
				uip_neighbor_periodic();
			}
		}
		if (tftp6_status == TFTP6_RETRY) 
			goto start_gain;
		if (tftp6_status == TFTP6_SUCCESS)
			break;

	} while (timer_expired(&app_timer) == 0);

	uip_udp_remove(tftp6_conn);
	tftp6_conn = NULL;
	TftpState = 0;

	if (tftp6_status == TFTP6_SUCCESS)
		return 1;
	if (tftp6_status == TFTP6_FAILURE)
		return 0;
	if (timer_expired(&app_timer)) {
		char *nretry;
		int noretry = 0;

		printf("TFTP6 timeout\n");
		if ((nretry = getenv ("netretry")) != NULL) {
			noretry = (strcmp (nretry, "no") == 0);
		}
		if (noretry) {
			return 0;
		}

		puts ("Starting again\n\n");
		goto start_gain;
	}
	return 1;
}
void tftp_send_rrq(void) {
	volatile u8_t *pkt = (u8_t *)uip_appdata;
	volatile u16_t *s;

	s = (u16_t *)pkt;
	*s++ = htons(TFTP_RRQ);
	pkt = (uchar *)s;
	strcpy ((char *)pkt, tftp_filename);
	pkt += strlen(tftp_filename) + 1;
	strcpy ((char *)pkt, "octet");
	pkt += 5 + 1 ;
	strcpy ((char *)pkt, "timeout"); 
	pkt += 7 + 1;
	sprintf((char *)pkt, "%d", TIMEOUT);
	pkt += strlen((char *)pkt) + 1;

	uip_send(uip_appdata, pkt - (u8_t *)uip_appdata);
}
void tftp_send_ack(void) {
	volatile u8_t *pkt = (u8_t *)uip_appdata;
	volatile u16_t *s;

	s = (u16_t *)pkt;
	*s++ = htons(TFTP_ACK);
	*s++ = htons(TftpBlock);
	pkt = (u8_t *)s;

	uip_send(uip_appdata, pkt - (u8_t *)uip_appdata);
}
#endif
