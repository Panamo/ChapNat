/*
 * In The Name Of God
 * ========================================
 * [] File Name : chsession.h
 *
 * [] Creation Date : 25-03-2015
 *
 * [] Last Modified : Wed 25 Mar 2015 03:01:17 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef CHSESSION_H
#define CHSESSION_H

struct chsession {
	struct chevent *head;
	void (*cleaner)(struct chevent *event);
};

struct chsession *chsession_new(void);

/*
 * for all event, this function first use cleaner@chsession
 * freeing user_data then free chevent itself
*/
void chsession_free(struct chsession *session);

void chsession_register_cleaner(struct chsession *session,
		void (*cleaner)(struct chevent *event));

void chsession_add_event(struct chsession *session,
		struct chevent *event);

/* TODO */
void chsession_remove_event(struct chsession *session,
		const struct chevent *event);

void chsession_dispatcher(const struct chsession *session,
		const void *data,
		const struct chmessage *message,
		const void *user_data);

#endif
