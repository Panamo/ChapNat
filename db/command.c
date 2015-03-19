/*
 * In The Name Of God
 * ========================================
 * [] File Name : command.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Fri 20 Mar 2015 12:17:29 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <string.h>
#include <stdio.h>

#include "message.h"
#include "command.h"
#include "net.h"
#include "users.h"

void sgin_command(const struct message *message, int socket_fd)
{
}

void sgup_command(const struct message *message, int socket_fd)
{
	add_user(message, socket_fd);
}

void newg_command(const struct message *message, int socket_fd)
{
}

void command_dispatcher(int socket_fd, const struct message *message)
{
	if (!strcmp(message->verb, "sgnin"))
		sgin_command(message, socket_fd);
	else if (!strcmp(message->verb, "sgup"))
		sgup_command(message, socket_fd);
	else if (!strcmp(message->verb, "newg"))
		newg_command(message, socket_fd);
}
