/*
 * In The Name Of God
 * ========================================
 * [] File Name : message.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Wed Jan 28 14:49:18 2015
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
	int retval = fprintf(dest, "%s %s %s %d\n%s", message->verb,
			message->dest_id, message->src_id,
			message->m_size, message->body);
	ulog("%s %s %s %d\n%s", message->verb,
			message->dest_id, message->src_id,
			message->m_size, message->body);
	fflush(dest);
	return retval;
}

int deserialize_message(FILE *src, struct message *message)
{
	int retval = 0;

	if (fscanf(src, "%s", message->verb) != 1)
		return -1;
	retval += strlen(message->verb);

	if (fscanf(src, "%s", message->dest_id) != 1)
		return -1;
	retval += strlen(message->dest_id);

	if (fscanf(src, "%s", message->src_id) != 1)
		return -1;
	retval += strlen(message->src_id);

	if (fscanf(src, "%d", &message->m_size) != 1)
		return -1;

	message->body = malloc(message->m_size * sizeof(char) + 1);
	/* Read message body start indicator ('\n') */
	fgetc(src);
	retval += fread(message->body, message->m_size,
			sizeof(char), src);

	return retval;
}
