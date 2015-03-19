/*
 * In The Name Of God
 * ========================================
 * [] File Name : message.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Thu 19 Mar 2015 11:50:18 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"
#include "message.h"

int serialize_message(FILE *dest, const struct message *message)
{
	int retval = fprintf(dest, "%s %s %s %s", message->verb,
			message->user_id, message->pass,
			message->user);
	if (retval < 0)
		sdie("Socket:");
	ulog("%s %s %s %s", message->verb,
			message->user_id, message->pass,
			message->user);
	fflush(dest);
	return retval;
}

int deserialize_message(FILE *src, struct message *message)
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

	
	return retval;
}
