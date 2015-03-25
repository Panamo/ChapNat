/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 25-03-2015
 *
 * [] Last Modified : Wed 25 Mar 2015 04:12:19 PM IRDT
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

void recv_handler(const struct chmessage *message,
		const void *user_data)
{
	const int *fd = (const int *) user_data;
	printf("recv socket fd: %d\n", *fd);
}


int event_dispatcher(const struct chevent *event,
		const void *data)
{
	const int *event_id = (const int *) event->data;
	const int *data_id = (const int *) data;

	if (*event_id == *data_id)
		return 1;
	return 0;
}

void event_cleaner(struct chevent *event)
{
	free(event->data);
}

int main(int argc, char *argv[])
{
	struct chevent *send, *recv;
	int *send_id, *recv_id;
	int *fd;
	struct chsession *session;

	send = chevent_new();
	send_id = malloc(sizeof(int));
	*send_id = 10;
	chevent_register_handler(send, send_handler);
	chevent_register_data(send, send_id);

	recv = chevent_new();
	recv_id = malloc(sizeof(int));
	*recv_id = 20;
	chevent_register_handler(recv, recv_handler);
	chevent_register_data(recv, recv_id);


	session = chsession_new();
	chsession_add_event(session, send);
	chsession_add_event(session, recv);
	chsession_register_cleaner(session, event_cleaner);
	chsession_register_dispatcher(session, event_dispatcher);

	fd = malloc(sizeof(int));
	*fd = 100;
	chsession_dispatch(session, send_id, NULL, fd);
	chsession_dispatch(session, recv_id, NULL, fd);
	free(fd);

	chsession_delete(session);
}
