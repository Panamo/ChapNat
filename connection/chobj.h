/*
 * In The Name Of God
 * ========================================
 * [] File Name : chobj.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef CHOBJ_H
#define CHOBJ_H

#include <netinet/in.h>

struct chobj {
	char id[255];
	GSList *child;

	int fd;
	struct sockaddr_in client_addr;
};

struct chobj *chobj_new(const char *id, int socket,
	struct sockaddr_in addr);

void chobj_del(struct chobj *chobj);

void chobj_add_child(struct chobj *parent,
	struct chobj *child);

void chobj_del_child(struct chobj *parent,
	struct chobj *child);

#endif
