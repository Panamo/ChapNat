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

int serialize_message(FILE *dest, const struct message *message)
{
	int return_value = fprintf(dest, "%s %s %s %zu\n%s", message->verb,
		message->dest_id, message->src_id,
		message->m_size, message->body);
	if (return_value < 0)
		sdie("Socket:");
	ulog("%s %s %s %zu\n%s", message->verb,
		message->dest_id, message->src_id,
		message->m_size, message->body);
	fflush(dest);
	return return_value;
}

int deserialize_message(FILE *src, struct message *message)
{
	int return_value = 0;

	if (fscanf(src, "%s", message->verb) != 1)
		return -1;
	return_value += strlen(message->verb);

	if (fscanf(src, "%s", message->dest_id) != 1)
		return -1;
	return_value += strlen(message->dest_id);

	if (fscanf(src, "%s", message->src_id) != 1)
		return -1;
	return_value += strlen(message->src_id);

	if (fscanf(src, "%zu", &message->m_size) != 1)
		return -1;

	message->body = calloc(message->m_size + 1, sizeof(char));

	/* Read message body start indicator ('\n') */
	fgetc(src);
	return_value += fread(message->body, message->m_size,
		sizeof(char), src);

	return return_value;
}
