/*
 * In The Name Of God
 * ========================================
 * [] File Name : group_id.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Wed 31 Dec 2014 05:13:54 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "common.h"

#ifndef GROUP_ID_H
#define GROUP_ID_H

typedef struct{
	int id;

	int number;	//showing last empty cell and size !! ;-)))

	int socket_fds[MAX_CONN];
} GroupId;

void add_node(int socket_fd, GroupId* group_id);

int remove_node(int socket_fd, GroupId* group_id);

#endif
