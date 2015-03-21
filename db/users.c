/*
 * In The Name Of God
 * ========================================
 * [] File Name : users.h
 *
 * [] Creation Date : 25-01-2015
 *
 * [] Last Modified : Sat 21 Mar 2015 08:52:54 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include <openssl/sha.h>

#include "message.h"
#include "net.h"
#include "users.h"
#include "common.h"
#include "asprintf.h"

PGconn *open_user(void)
{
	PGconn *retval;
	const char *dburl;

	dburl = "postgresql://postgre:Parham13730321@localhost/users";
	retval = PQconnectdb(dburl);
	
	/* Check to see that the backend connection was successfully made */
	if (PQstatus(retval) != CONNECTION_OK) {
		fprintf(stderr, "Connection to database failed: %s",
				PQerrorMessage(retval));
		PQfinish(retval);
		exit(1);
	}

	return retval;
}


void close_user(PGconn *conn)
{
	PQfinish(conn);
}

void add_user(const struct message *message, int socket)
{
	struct message replay;
	char *query;
  	unsigned char hashpas[SHA_DIGEST_LENGTH];

    	SHA1(message->pass, sizeof(message->pass) - 1, hashpas);
	
	asprintf(&query, "INSERT INTO users VALUES('','%s','%s');", message->user, hashpas);
	ulog("%s", query);

	PGconn *conn = open_user();
	PQexec(conn, query);
	close_user(conn);

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
