/*
 * In The Name Of God
 * ========================================
 * [] File Name : chobj.c
 *
 * [] Creation Date : 26-01-2015
 *
 * [] Last Modified : Mon Jan 26 17:23:02 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <glib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#include "chobj.h"

struct chobj *chobj_new(const char *id, int socket,
		struct sockaddr_in addr)
{
	struct chobj *new = g_new(struct chobj, 1);
	new->child = NULL;
	new->fd = socket;
	strcpy(new->id, id);
	new->client_addr = addr;
	return new;
}

void chobj_add_child(struct chobj *parent,
		struct chobj *child)
{
	parent->child = g_slist_append(parent->child, child);
}

void chobj_del_child(struct chobj *parent,
		struct chobj *child)
{
	
}
