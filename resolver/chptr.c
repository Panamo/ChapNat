/*
 * In The Name Of God
 * ========================================
 * [] File Name : ip.c
 *
 * [] Creation Date : 03-04-2015
 *
 * [] Last Modified : Tue 07 Apr 2015 08:27:02 AM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>

#include "chptr.h"
#include "common.h"

uint32_t chptr_checksum(const struct chptrhdr *chptr)
{
	uint64_t sum = 0;
	uint32_t checksum = 0;
	int len = sizeof(struct chptrhdr);
	const uint32_t *chptr_header = (const uint32_t *) chptr;

	while (len > 1) {
		sum += *chptr_header++;
		len -= sizeof(uint32_t);
	}
	if (len)
		sum += *((uint16_t *)(chptr_header));

	/* handle sum carry !! :-) this is good !! */
	sum = (sum >> 32) + (sum & 0xFFFFFFFF);
	sum += (sum >> 32);

	/* calculate 1's complement of the sum */
	checksum = (uint32_t) ~sum;

	return checksum;
}
