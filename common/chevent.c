/*
 * In The Name Of God
 * ========================================
 * [] File Name : chevent.c
 *
 * [] Creation Date : 25-03-2015
 *
 * [] Last Modified : Wed 25 Mar 2015 03:47:05 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdlib.h>
#include <stdio.h>

#include "chmessage.h"
#include "chevent.h"

struct chevent *chevent_new(void)
{
	struct chevent *new;
	
	new = malloc(sizeof(struct chevent));
	new->handler = NULL;
	new->dispatcher = NULL;
	new->data = NULL;
	return new;
}

void chevent_delete(struct chevent *event)
{
	free(event);
}

void chevent_register_handler(struct chevent *event,
		void (*handler)(const struct chmessage *message,
			const void *user_data))
{
	event->handler = handler;
}

void chevent_register_dispatcher(struct chevent *event,
		int (*dispatcher)(const void *indata,
			const void *staticdata))
{
	event->dispatcher = dispatcher;
}

void chevent_register_data(struct chevent *event,
		const void *data)
{
	event->data = data;
}

void chevent_minor_dispatcher(const struct chevent *event,
		const void *data,
		const struct chmessage *message,
		const void *user_data)
{
	int dispatch = 1;

	if (event->dispatcher)
		dispatch = event->dispatcher(data, event->data);
	if (dispatch)
		if (event->handler)
			event->handler(message, user_data);

}
