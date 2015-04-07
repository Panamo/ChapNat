/*
 * In The Name Of God
 * ========================================
 * [] File Name : chptr.h
 *
 * [] Creation Date : 07-04-2015
 *
 * [] Last Modified : Tue 07 Apr 2015 08:29:30 AM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef CHPTR_H
#define CHPTR_H

struct chptrhdr {
	uint8_t verb[4];
	uint16_t ttl;
	/* flags */
	uint16_t qus:1,
		 ans:1,
		 unused:14;
	uint32_t dest_ip;
	uint32_t user_id;
	uint32_t check;
};

uint32_t chptr_checksum(const struct chptrhdr *chptr);

#endif
