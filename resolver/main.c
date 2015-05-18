/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
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
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>

#include "common.h"
#include "chptr.h"
#include "chbuff.h"
#include "dht.h"

uint32_t haddr;
uint16_t hport;

int main(int argc, char *argv[])
{
	
	if (argc < 3)
		udie("usage: %s <Propagated IP> <Propagated Port>\n", argv[0]);

	hport = atoi(argv[2]);
	haddr = inet_addr(argv[1]);

	uint32_t daddr;
	int sockfd;
	struct chbuff *packet;

	daddr = inet_addr("255.255.255.255");

	sockfd = socket(AF_INET, SOCK_RAW, 110);
	if (sockfd < 0)
		sdie("socket()");

	const int on = 1;

	/* We shall provide IP headers */
	if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL,
				(const char *) &on, sizeof(on)) == -1)
		sdie("setsockopt()");
	/* We want BROADCAST */
	if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST,
				(const char *) &on, sizeof(on)) == -1)
		sdie("setsockopt()");

	/* Starting broadcasting .... */

	/* Create chbuff */
	packet = chbuff_new();

	/* Version */
	packet->ip.version = 4;
	/* Header Length */
	/* can you use (packet_len * 8) / 32 ? */
	packet->ip.ihl = 5;
	/* Type Of Service */
	packet->ip.tos = 0;
	/* Total length */
	packet->ip.tot_len = htons(packet->len);
	/* Fragmentation Offset */
	packet->ip.frag_off = 0;
	/* Time To Live */
	packet->ip.ttl = 73;
	/* Protocol */
	packet->ip.protocol = 110;
	/* Destination Address */
	packet->ip.daddr = daddr;
	
	packet->chptr.verb[0] = 's';
	packet->chptr.verb[1] = 'e';
	packet->chptr.verb[2] = 'n';
	packet->chptr.verb[3] = 'd';
	packet->chptr.ans = 0;
	packet->chptr.qus = 1;
	packet->chptr.haddr = haddr;
	packet->chptr.hport = hport;
	packet->chptr.check = chptr_checksum(&packet->chptr);

	chbuff_serialize(packet);

	struct sockaddr_in addr;
	size_t addr_len = sizeof(addr);

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = daddr;
	memset(&addr.sin_zero, 0, sizeof(addr.sin_zero));

	if (sendto(sockfd, packet->buff, packet->len, 0,
				(struct sockaddr *) &addr,
				addr_len) < 1)
		sdie("sendto()");
	chbuff_delete(packet);

	/* Starting server .... */
	while (1) {
		packet = chbuff_new();
		if (recvfrom(sockfd, packet->buff, packet->len, 0,
					(struct sockaddr *) &addr,
					(socklen_t *) &addr_len) < 1)
			sdie("recvfrom()");
		chbuff_deserialize(packet);
		if (packet->chptr.qus) {
			unload_info(packet);
			chbuff_delete(packet);
			packet = chbuff_new();
			load_info(packet);
			chbuff_serialize(packet);
			if (sendto(sockfd, packet->buff, packet->len, 0,
						(struct sockaddr *) &addr,
						addr_len) < 1)
				sdie("sendto()");
			chbuff_delete(packet);
		}
		else if (packet->chptr.ans) {
			unload_info(packet);
			chbuff_delete(packet);
		} else {
			chbuff_delete(packet);
		}
	}
}
