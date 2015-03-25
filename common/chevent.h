/*
 * In The Name Of God
 * ========================================
 * [] File Name : chevent.h
 *
 * [] Creation Date : 25-03-2015
 *
 * [] Last Modified : Wed 25 Mar 2015 02:12:54 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef CHEVENT_H
#define CHEVENT_H

struct chevent {
	void (*handler)(const struct chmessage *message,
			const void *user_data);
	int (*dispatcher)(const void *data);
	const void *data;
};

struct chevent *chevnet_new(void);

void chevent_delete(struct chevent *event);

void chevent_register_handler(struct chevent *event,
		void (*handler)(const struct chmessage *message,
			const void *user_data));

void chevent_register_dispatcher(struct chevent *event,
		int (*dispatchet)(const void *data));

void chevent_register_data(struct chevent *event,
		const void *data);

void chevent_minor_dispatcher(const struct chevent *event,
		const void *data,
		const struct chmessage *message,
		const void *user_data);

#endif
