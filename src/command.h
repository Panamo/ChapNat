/*
 * In The Name Of God
 * ========================================
 * [] File Name : command.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Tue 30 Dec 2014 11:31:05 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "message.h"

#ifndef COMMAND_H
#define COMMAND_H

void command_dispatcher(int socket_fd, Message* message);

void join_command(int group_id, int socket_fd);

void leave_command(int group_id, int socket_fd);

void send_command(int group_id, Message* message, int socket_fd); 

#endif
