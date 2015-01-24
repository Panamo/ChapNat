/*
 * In The Name Of God
 * ========================================
 * [] File Name : message.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Sat Jan 24 18:01:23 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "message.h"

int serialize_message(FILE *dest, const struct message *message)
{
	return fprintf(dest, "%s %s %d\n%s", message->verb,
			message->dest_id, message->m_size, message->body);
}

int deserialize_message(FILE *src, struct message *message)
{
	if (fscanf(src, "%s", message->verb) != 1)
		return -1;

	if (fscanf(src, "%s", message->dest_id) != 1)
		return -1;

	if (fscanf(src, "%d", &message->m_size) != 1)
		return -1;

	message->body = malloc(message->m_size * sizeof(char) + 1);
	/* Read message body start indicator ('\n') */
	fgetc(src);
	return fread(message->body, message->m_size, sizeof(char), src);

}
