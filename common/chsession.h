/*
 * In The Name Of God
 * ========================================
 * [] File Name : chsession.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef CHSESSION_H
#define CHSESSION_H

struct chsession {
	struct chevent *head;

	void (*cleaner)(struct chevent *event);

	int (*dispatcher)(const struct chevent *event,
		const void *data);
};

struct chsession *chsession_new(void);

/*
 * for all event, this function first use cleaner@chsession
 * freeing user_data then free chevent itself
*/
void chsession_delete(struct chsession *session);

void chsession_register_cleaner(struct chsession *session,
	void (*cleaner)(struct chevent *event));

void chsession_register_dispatcher(struct chsession *session,
	int (*dispatcher)(const struct chevent *event,
		const void *data));

void chsession_add_event(struct chsession *session,
	struct chevent *event);

void chsession_remove_event(struct chsession *session,
	const void *data);

void chsession_dispatch(const struct chsession *session,
	const void *data,
	const struct chmessage *message,
	const void *user_data);

#endif
