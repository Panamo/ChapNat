/*
 * In The Name Of God
 * ========================================
 * [] File Name : users.h
 *
 * [] Creation Date : 25-01-2015
 *
 * [] Last Modified : Fri 20 Mar 2015 03:05:27 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#include "message.h"
#include "net.h"
#include "users.h"
#include "common.h"
#include "asprintf.h"

void add_user(const struct message *message, int socket)
{
	struct message replay;
	char *query;
  	unsigned char hashpas[SHA_DIGEST_LENGTH];

    	SHA1(message->pass, sizeof(message->pass) - 1, hashpas);
	
	asprintf(&query, "INSERT INTO users VALUES('','%s','%s');", message->user, hashpas);
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
	struct message replay;
	char *query;
  	unsigned char hashpas[SHA_DIGEST_LENGTH];

    	SHA1(message->pass, sizeof(message->pass) - 1, hashpas);
	
	asprintf(&query, "SELECT * FROM users WHERE username='%s' and password='%s';", message->user, hashpas);
	ulog("%s", query);
	free(query);

	strcpy(replay.verb, "st00");
	strcpy(replay.user_id, "0");
	strcpy(replay.user, "-");
	strcpy(replay.pass, "-");

	send_message(&replay, socket);

}
