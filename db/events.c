/*
 * In The Name Of God
 * ========================================
 * [] File Name : events.c
 *
 * [] Creation Date : 26-03-2015
 *
 * [] Last Modified : Wed 08 Apr 2015 09:32:08 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <chmessage.h>
#include <chevent.h>
#include <chsession.h>

#include "message.h"
#include "users.h"
#include "events.h"
#include "asprintf.h"

static void sgin_handler(const struct chmessage *chmessage,
		const void *user_data)
{
	const struct message *message;
	const int* socket_fd;
	
	socket_fd = (const int *) user_data;
	message = (const struct message *) chmessage;
	get_user(message, *socket_fd);

}

static void sgup_handler(const struct chmessage *chmessage,
		const void *user_data)
{
	const struct message *message;
	const int* socket_fd;
	
	socket_fd = (const int *) user_data;
	message = (const struct message *) chmessage;
	add_user(message, *socket_fd);
}

static void newg_handler(const struct message *message, int socket_fd)
{
}

static void event_cleaner(struct chevent *event)
{
	free(event->data);
}

static int event_dispatcher(const struct chevent *event,
		const void *data)
{
	const char *event_in_name;
	const char *event_name;
	
	event_in_name = (const char *) data;
	event_name = (const char *) event->data;
	if (!strcmp(event_in_name, event_name))
		return 1;
	return 0;
}

struct chsession *events_init(void)
{
	struct chsession *session;
	char *sgup_id, *sgin_id;
	struct chevent *sgup, *sgin;

	session = chsession_new();
	chsession_register_cleaner(session, event_cleaner);
	chsession_register_dispatcher(session, event_dispatcher);

	asprintf(&sgup_id, "sgup");
	sgup = chevent_new();
	chevent_register_handler(sgup, sgup_handler);
	chevent_register_data(sgup, sgup_id);
	chsession_add_event(session, sgup);

	asprintf(&sgin_id, "sgin");
	sgin = chevent_new();
	chevent_register_handler(sgin, sgin_handler);
	chevent_register_data(sgin, sgin_id);
	chsession_add_event(session, sgin);

	return session;
}

void events_clear(struct chsession *session)
{
	chsession_delete(session);
}
