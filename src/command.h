/*
 * In The Name Of God
 * ========================================
 * [] File Name : command.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Wed 31 Dec 2014 07:26:45 AM IRST
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
/*
 * verb = send
 * arg = message
 * group_id != -1
*/
void send_command(int group_id, Message* message, int socket_fd); 

#endif
