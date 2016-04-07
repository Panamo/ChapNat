/*
 * In The Name Of God
 * ========================================
 * [] File Name : message.c
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"
#include "message.h"

int message_serialize(FILE *dst, const struct message *message)
{
	int retval = fprintf(dst, "%s %s %s %s", message->verb,
			message->user_id, message->pass,
			message->user);
	if (retval < 0)
		sdie("Socket:");
	ulog("%s %s %s %s", message->verb,
			message->user_id, message->pass,
			message->user);
	fflush(dst);
	return retval;
}

int message_deserialize(FILE *src, struct message *message)
{
	int retval = 0;

	if (fscanf(src, "%s", message->verb) != 1)
		return -1;
	retval += strlen(message->verb);

	if (fscanf(src, "%s", message->user_id) != 1)
		return -1;
	retval += strlen(message->user_id);

	if (fscanf(src, "%s", message->pass) != 1)
		return -1;
	retval += strlen(message->pass);

	if (fscanf(src, "%s", message->user) != 1)
		return -1;
	retval += strlen(message->user);

	ulog("%s %s %s %s", message->verb,
			message->user_id, message->pass,
			message->user);

	return retval;
}
