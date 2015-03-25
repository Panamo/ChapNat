/*
 * In The Name Of God
 * ========================================
 * [] File Name : chsession.c
 *
 * [] Creation Date : 25-03-2015
 *
 * [] Last Modified : Wed 25 Mar 2015 03:48:01 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
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
	return new;
}

void chsession_free(struct chsession *session)
{
	struct chevent *it, *old;

	it = session->head;
	while (it) {
		if (session->cleaner)
			session->cleaner(it);
		old = it->next;
		free(it);
		it = old;
	}
}

void chsession_register_cleaner(struct chsession *session,
		void (*cleaner)(struct chevent *event))
{
	session->cleaner = cleaner;
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

/* TODO */
void chsession_remove_event(struct chsession *session,
		const struct chevent *event)
{
}

void chsession_dispatcher(const struct chsession *session,
		const void *data,
		const struct chmessage *message,
		const void *user_data)
{
	struct chevent *it;
	
	it = session->head;
	while (it) {
		chevent_minor_dispatcher(it, data, message, user_data);
		it = it->next;
	}
}
