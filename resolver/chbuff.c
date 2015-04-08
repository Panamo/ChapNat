/*
 * In The Name Of God
 * ========================================
 * [] File Name : chbuff.c
 *
 * [] Creation Date : 09-04-2015
 *
 * [] Last Modified : Thu 09 Apr 2015 12:51:18 AM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>

#include "chbuff.h"
#include "chptr.h"

struct chbuff *chbuff_new(void)
{
	struct chbuff *new;

	new = malloc(sizeof(struct chbuff));
	new->buff = malloc(sizeof(struct chptrhdr) + sizeof(struct iphdr));
	new->len = sizeof(struct chptrhdr) + sizeof(struct iphdr);
	return new;
}

void chbuff_serialize(struct chbuff *buff)
{
	/* write ip header */
	memcpy(buff->buff, &buff->ip, sizeof(struct iphdr));
	/* write chptr header */
	memcpy(buff->buff + sizeof(struct iphdr), &buff->chptr, sizeof(struct chptrhdr));
}

void chbuff_deserialize(struct chbuff *buff)
{
	/* read ip header */
	memcpy(&buff->ip, buff->buff, sizeof(struct iphdr));
	/* read chptr header */
	memcpy(&buff->chptr, buff->buff + sizeof(struct iphdr), sizeof(struct chptrhdr));

}

void chbuff_delete(struct chbuff *buff)
{
	if (buff->buff)
		free(buff->buff);
	free(buff);
}
