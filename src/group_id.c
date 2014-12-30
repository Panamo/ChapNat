/*
 * In The Name Of God
 * ========================================
 * [] File Name : group_id.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Tue 30 Dec 2014 11:31:04 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "group_id.h"

void add_node(int socket_fd, GroupId* group_id){
	int i = 0;
	for(i = 0; i < group_id->number; i++){
		if(group_id->socket_fds[i] == socket_fd){
			return;
		}
	}
	group_id->socket_fds[group_id->number] = socket_fd;
	group_id->number++;
}

int remove_node(int socket_fd, GroupId* group_id){
	int i = 0;
	for(i = 0; i < group_id->number; i++){
		if(group_id->socket_fds[i] == socket_fd){
			group_id->number--;
			if(group_id->number > 0){
				group_id->socket_fds[i] = group_id->socket_fds[group_id->number];
			}
			return socket_fd;
		}
	}
	return -1;
}


