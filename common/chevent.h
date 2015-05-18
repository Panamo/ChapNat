/*
 * In The Name Of God
 * ========================================
 * [] File Name : chevent.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/

#ifndef CHEVENT_H
#define CHEVENT_H

struct chevent {
	void (*handler)(const struct chmessage *message,
		const void *user_data);

	void *data;

	struct chevent *next;
};

struct chevent *chevent_new(void);

/*
 * please before using this function,
 * free user_data in chevent
*/
void chevent_delete(struct chevent *event);

void chevent_register_handler(struct chevent *event,
	void (*handler)(const struct chmessage *message,
		const void *user_data));

void chevent_register_data(struct chevent *event,
	void *data);

/*
 * this function first call dispatcher@chevent and if it
 * return 1 then it call handler@chevent.
*/
void chevent_minor_dispatcher(const struct chevent *event,
	const struct chmessage *message,
	const void *user_data);

#endif
