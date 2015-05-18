/*
 * In The Name Of God
 * ========================================
 * [] File Name : chbuff.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef CHBUFF_H
#define CHBUFF_H

#include <netinet/ip.h>

#include "chptr.h"

struct chbuff {
	size_t len;
	void *buff;
	struct iphdr ip;
	struct chptrhdr chptr;
};

struct chbuff *chbuff_new(void);

void chbuff_serialize(struct chbuff *buff);

void chbuff_deserialize(struct chbuff *buff);

void chbuff_delete(struct chbuff *buff);

#endif
