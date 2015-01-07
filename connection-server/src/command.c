/*
 * In The Name Of God
 * ========================================
 * [] File Name : command.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Tue 30 Dec 2014 11:31:03 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <string.h>
#include <stdio.h>

#include "command.h"
#include "group_id.h"
#include "server_net.h"

static GroupId groups[1024];
static int number;

void command_dispatcher(int socket_fd, Message* message){
	if(strcmp(message->verb, "JOIN") == 0){
		join_command(message->group_id, socket_fd);	
	}else if(strcmp(message->verb, "LEAVE") == 0){
		leave_command(message->group_id, socket_fd);	
	}else if(strcmp(message->verb, "SEND") == 0){	
		send_command(message->group_id, message, socket_fd);	
	}
}

void join_command(int group_id, int socket_fd){
	int i = 0;

	for(i = 0; i < number; i++){
		if(groups[i].id == group_id){
			add_node(socket_fd, &groups[i]);
			return;
		}
	}
	groups[number].id = group_id;	
	add_node(socket_fd, &groups[number]);
	number++;
}

void leave_command(int group_id, int socket_fd){
	int i = 0;
	for(i = 0; i < number; i++){
		if(groups[i].id == group_id){
			remove_node(socket_fd, &groups[i]);
			if(groups[i].number == 0){
				number--;
				if(number > 0){
					groups[i] = groups[number];
				}
			}
		}
	}
}

void send_command(int group_id, Message* message, int socket_fd){
	int i = 0;
	for(i = 0; i < number; i++){
		if(groups[i].id == group_id){
			int j = 0;
			for(j = 0; j < groups[i].number; j++){
				send_message(message, groups[i].socket_fds[j]);
			}
		}
	}
}

