/*
 * In The Name Of God
 * ========================================
 * [] File Name : chbuff.h
 *
 * [] Creation Date : 09-04-2015
 *
 * [] Last Modified : Thu 09 Apr 2015 12:51:25 AM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef CHBUFF_H
#define CHBUFF_H

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
