/*
 * In The Name Of God
 * ========================================
 * [] File Name : events.c
 *
 * [] Creation Date : 26-03-2015
 *
 * [] Last Modified : Thu 26 Mar 2015 11:06:19 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>

#include "message.h"
#include "users.h"
#include "events.h"

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

