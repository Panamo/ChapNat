/*
 * In The Name Of God
 * ========================================
 * [] File Name : users.h
 *
 * [] Creation Date : 25-01-2015
 *
 * [] Last Modified : Fri 20 Mar 2015 12:20:50 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "message.h"
#include "net.h"
#include "users.h"
#include "common.h"
#include "asprintf.h"

void add_user(const struct message *message, int socket)
{
	struct message replay;
	char *query;

	asprintf(&query, "INSERT INTO users VALUES('','%s','%s');", message->user, message->pass);
	ulog("%s", query);
	free(query);

	strcpy(replay.verb, "st10");
	strcpy(replay.user_id, "0");
	strcpy(replay.user, "-");
	strcpy(replay.pass, "-");

	send_message(&replay, socket);
}

void get_user(const struct message *message, int socket)
{
}
