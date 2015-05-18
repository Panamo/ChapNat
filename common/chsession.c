/*
 * In The Name Of God
 * ========================================
 * [] File Name : chsession.c
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <stdlib.h>

#include "chmessage.h"
#include "chevent.h"
#include "chsession.h"

struct chsession *chsession_new(void)
{
	struct chsession *new;

	new = malloc(sizeof(struct chsession));
	new->head = NULL;
	new->cleaner = NULL;
	new->dispatcher = NULL;
	return new;
}

void chsession_delete(struct chsession *session)
{
	struct chevent *it, *old;

	it = session->head;
	while (it) {
		if (session->cleaner)
			session->cleaner(it);
		old = it->next;
		chevent_delete(it);
		it = old;
	}
	free(session);
}

void chsession_register_cleaner(struct chsession *session,
	void (*cleaner)(struct chevent *event))
{
	session->cleaner = cleaner;
}

void chsession_register_dispatcher(struct chsession *session,
	int (*dispatcher)(const struct chevent *event,
		const void *data))
{
	session->dispatcher = dispatcher;
}


void chsession_add_event(struct chsession *session,
	struct chevent *event)
{
	if (!session->head) {
		session->head = event;
		event->next = NULL;
		return;
	}

	struct chevent *it;

	it = session->head;
	while (it->next)
		it = it->next;
	it->next = event;
	event->next = NULL;
}

void chsession_remove_event(struct chsession *session,
	const void *data)
{
	struct chevent *it, *old;

	it = session->head;
	while (it->next &&
	       !session->dispatcher(it->next, data)) {
		it = it->next;
	}
	if (it->next &&
	    session->dispatcher(it->next, data)) {
		old = it->next;
		it->next = it->next->next;
		if (session->cleaner)
			session->cleaner(old);
		chevent_delete(old);
	}

}

void chsession_dispatch(const struct chsession *session,
	const void *data,
	const struct chmessage *message,
	const void *user_data)
{
	struct chevent *it;

	it = session->head;
	while (it) {
		if (session->dispatcher(it, data))
			chevent_minor_dispatcher(it, message, user_data);
		it = it->next;
	}
}
