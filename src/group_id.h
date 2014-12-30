/*
 * In The Name Of God
 * ========================================
 * [] File Name : group_id.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Tue 30 Dec 2014 11:31:06 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "constants.h"

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
