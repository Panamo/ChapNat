/*
 * In The Name Of God
 * ========================================
 * [] File Name : command.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Wed 18 Mar 2015 12:33:12 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <string.h>
#include <stdio.h>

#include "message.h"
#include "users.h"
#include "command.h"
#include "net.h"

void command_dispatcher(int socket_fd, const struct message *message)
{
	if (!strcmp(message->verb, "signin"))
	else if (!strcmp(message->verb, "leave"))
	else if (!strcmp(message->verb, "send"))
	else if (!strcmp(message->verb, "check"))
}
