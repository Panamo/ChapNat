/*
 * In The Name Of God
 * ========================================
 * [] File Name : sockets.c
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <glib.h>

#include "sockets.h"
#include "chobj.h"
#include "chdef.h"
#include "users.h"
#include "common.h"

GSList *socket_fds;

void add_socket(int *fd)
{
	ulog("socket %d is added.\n", *fd);
	socket_fds = g_slist_append(socket_fds, fd);
}

void del_socket(int *fd)
{
	struct chobj *find = container_of(fd, struct chobj, fd);

	ulog("Start removing : %s\n", find->id);
	del_user(find->id);
	socket_fds = g_slist_remove(socket_fds, fd);
}

int *get_socket(int index)
{
	return g_slist_nth_data(socket_fds, index);
}

int get_socket_size(void)
{
	return g_slist_length(socket_fds);
}
