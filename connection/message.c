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

int message_serialize(FILE *dest, const struct message *message)
{
	int return_value = fprintf(dest, "%s %s %s %zu\n%s", message->verb,
		message->dst_id, message->src_id,
		message->m_size, message->body);
	if (return_value < 0)
		sdie("Socket:");
	ulog("%s %s %s %zu\n%s", message->verb,
		message->dst_id, message->src_id,
		message->m_size, message->body);
	fflush(dest);
	return return_value;
}

int message_deserialize(FILE *src, struct message *message)
{
	int return_value = 0;

	if (fscanf(src, "%s", message->verb) != 1)
		return -1;
	return_value += strlen(message->verb);

	if (fscanf(src, "%s", message->dst_id) != 1)
		return -1;
	return_value += strlen(message->dst_id);

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
