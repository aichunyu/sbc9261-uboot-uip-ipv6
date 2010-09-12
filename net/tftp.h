/*
 *	LiMon - BOOTP/TFTP.
 *
 *	Copyright 1994, 1995, 2000 Neil Russell.
 *	(See License)
 */

#ifndef __TFTP_H__
#define __TFTP_H__
#undef	ET_DEBUG

#define WELL_KNOWN_PORT	69		/* Well known TFTP port #		*/
#define TIMEOUT		5		/* Seconds to timeout for a lost pkt	*/
					/* (for checking the image size)	*/
#define HASHES_PER_LINE	65		/* Number of "loading" hashes per line	*/

/*
 *	TFTP operations.
 */
#define TFTP_RRQ	1
#define TFTP_WRQ	2
#define TFTP_DATA	3
#define TFTP_ACK	4
#define TFTP_ERROR	5
#define TFTP_OACK	6

#define STATE_RRQ	1
#define STATE_DATA	2
#define STATE_TOO_LARGE	3
#define STATE_BAD_MAGIC	4
#define STATE_OACK	5

#define TFTP_BLOCK_SIZE		512		    /* default TFTP block size	*/
#define TFTP_SEQUENCE_SIZE	((ulong)(1<<16))    /* sequence number is 16 bit */

/**********************************************************************/
/*
 *	Global functions and variables.
 */

/* tftp.c */
extern void	TftpStart (void);	/* Begin TFTP get */

extern __inline__ void
tftp_store_block (unsigned block, uchar * src, unsigned len);
/**********************************************************************/

#endif /* __TFTP_H__ */
