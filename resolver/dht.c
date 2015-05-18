/*
 * In The Name Of God
 * ========================================
 * [] File Name : dht.c
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "chptr.h"
#include "chbuff.h"
#include "dht.h"
#include "hinf.h"

void unload_info(struct chbuff *buff)
{
	if (buff->chptr.haddr != haddr ||
			buff->chptr.hport != hport) {
		struct in_addr ihaddr =
			(struct in_addr) {buff->chptr.haddr};

		printf("%s\n", inet_ntoa(ihaddr));
		printf("%hu\n", buff->chptr.hport);
		printf("%c\n", buff->chptr.verb[0]);
		printf("%c\n", buff->chptr.verb[1]);
		printf("%c\n", buff->chptr.verb[2]);
		printf("%c\n", buff->chptr.verb[3]);
		printf("%d\n", buff->chptr.ans);
		printf("%d\n", buff->chptr.qus);
	}
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
	buff->chptr.hport = hport;
	buff->chptr.haddr = haddr;
	buff->chptr.check = chptr_checksum(&buff->chptr);
}
