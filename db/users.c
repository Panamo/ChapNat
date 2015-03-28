/*
 * In The Name Of God
 * ========================================
 * [] File Name : users.h
 *
 * [] Creation Date : 25-01-2015
 *
 * [] Last Modified : Sun 29 Mar 2015 01:00:09 AM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>

#include "message.h"
#include "net.h"
#include "users.h"
#include "common.h"
#include "asprintf.h"

PGconn *open_user(void)
{
	PGconn *retval;
	const char *dburl;

	dburl = "postgresql://postgres:Parham13730321@localhost/chapat";
	retval = PQconnectdb(dburl);

	/* Check to see that the backend connection was successfully made */
	if (PQstatus(retval) != CONNECTION_OK) {
		fprintf(stderr, "Connection to database failed: %s\n",
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

	asprintf(&query, "INSERT INTO users (username, password) VALUES('%s','%s') RETURNING ID;",
			message->user, message->pass);
	ulog("%s", query);

	PGconn *conn = open_user();
	PGresult *res;

	res = PQexec(conn, query);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		strcpy(replay.verb, "st11");
		strcpy(replay.user_id, "-");
		strcpy(replay.user, "-");
		strcpy(replay.pass, "-");

		send_message(&replay, socket);

		fprintf(stderr, "INSERT failed: %s\n", PQerrorMessage(conn));
		PQfinish(conn);
		exit(1);
	}

	close_user(conn);

	PQclear(res);
	free(query);

	ulog("%s", PQgetvalue(res, 0, 0));

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

	asprintf(&query, "SELECT * FROM users WHERE username='%s' and password='%s';",
			message->user, message->pass);
	ulog("%s", query);
	free(query);

	strcpy(replay.verb, "st00");
	strcpy(replay.user_id, "0");
	strcpy(replay.user, "-");
	strcpy(replay.pass, "-");

	send_message(&replay, socket);

}
