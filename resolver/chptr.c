/*
 * In The Name Of God
 * ========================================
 * [] File Name : chptr.c
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
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
