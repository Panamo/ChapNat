/*
 * In The Name Of God
 * ========================================
 * [] File Name : chptr.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef CHPTR_H
#define CHPTR_H

struct chptrhdr {
	uint8_t verb[4];
	/* flags */
	uint16_t qus:1,
		ans:1,
		unused:14;
	uint32_t haddr;
	uint16_t hport;
	uint32_t check;
};

uint32_t chptr_checksum(const struct chptrhdr *chptr);

#endif
