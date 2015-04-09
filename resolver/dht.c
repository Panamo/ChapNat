/*
 * In The Name Of God
 * ========================================
 * [] File Name : dht.c
 *
 * [] Creation Date : 09-04-2015
 *
 * [] Last Modified : Thu 09 Apr 2015 05:20:59 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <arpa/inet.h>

#include "chptr.h"
#include "chbuff.h"
#include "dht.h"

void unload_info(struct chbuff *buff)
{
	printf("%x\n", buff->ip.saddr);
	printf("%c\n", buff->chptr.verb[0]);
	printf("%c\n", buff->chptr.verb[1]);
	printf("%c\n", buff->chptr.verb[2]);
	printf("%c\n", buff->chptr.verb[3]);
	printf("%d\n", buff->chptr.ans);
	printf("%d\n", buff->chptr.qus);
}

void load_info(struct chbuff *buff)
{
	/* Version */
	buff->ip.version = 4;
	/* Header Length */
	/* can you use (packet_len * 8) / 32 ? */
	buff->ip.ihl = 5;
	/* Type Of Service */
	buff->ip.tos = 0;
	/* Total length */
	buff->ip.tot_len = htons(buff->len);
	/* Fragmentation Offset */
	buff->ip.frag_off = 0;
	/* Time To Live */
	buff->ip.ttl = 73;
	/* Protocol */
	buff->ip.protocol = 110;
	
	buff->chptr.verb[0] = 's';
	buff->chptr.verb[1] = 'e';
	buff->chptr.verb[2] = 'n';
	buff->chptr.verb[3] = 'd';
	buff->chptr.ans = 1;
	buff->chptr.qus = 0;
	buff->chptr.ttl = 45;
	buff->chptr.user_id = 1373;
	buff->chptr.check = chptr_checksum(&buff->chptr);
}
