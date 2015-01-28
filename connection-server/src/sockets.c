/*
 * In The Name Of God
 * ========================================
 * [] File Name : sockets.c
 *
 * [] Creation Date : 28-01-2015
 *
 * [] Last Modified : Wed Jan 28 15:20:52 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <glib.h>

#include "sockets.h"

void add_socket(int *fd)
{
	socket_fds = g_slist_append(socket_fds, fd);
}

void del_socket(int *fd)
{
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
