/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 25-03-2015
 *
 * [] Last Modified : Wed 25 Mar 2015 03:45:26 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "chmessage.h"
#include "chevent.h"
#include "chsession.h"

void send_handler(const struct chmessage *message,
		const void *user_data)
{
	const int *fd = (const int *) user_data;
	printf("send socket fd: %d\n", *fd);
}

int send_dispatcher(const void *indata,
		const void *staticdata)
{
	const int *in_id = (const int *) indata;
	const int *static_id = (const int *) staticdata;
	if (*in_id == *static_id)
		return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	struct chevent *send;
	int *send_id;
	int *fd;
	struct chsession *session;

	send = chevent_new();
	send_id = malloc(sizeof(int));
	*send_id = 10;
	chevent_register_handler(send, send_handler);
	chevent_register_dispatcher(send, send_dispatcher);
	chevent_register_data(send, send_id);

	session = chsession_new();
	chsession_add_event(session, send);

	fd = malloc(sizeof(int));
	*fd = 100;

	chsession_dispatcher(session, send_id, NULL, fd);
}
