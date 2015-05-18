/*
 * In The Name Of God
 * ========================================
 * [] File Name : message.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>

#define MESSAGE_SIZE (255 * 4 + 32)

/*
 * message header fields must be separate with ' ', and
 * connection created over TCP so field sequence is important.
 * after message header there is just ONE '\n' and then message
 * body come.
 *
 * @verb: send join leave check
 *
 * @dest_id: It can be both group or a single client UUID
 *
 * @src_id: single source client UUID
 *
 * @size: sizeof message body in bytes
 *
 * +------------+--------------------------+------------+
 * |    verb    |   dest_id  |    src_id   |    size    |
 * +------------+--------------------------+------------+
 * |                                                    |
 * |                  Message Body                      |
 * |                                                    |
 * +----------------------------------------------------+
*/

struct message {
	char verb[10];
	char dest_id[255];
	char src_id[255];
	size_t m_size;
	char *body;
};

int serialize_message(FILE *dest, const struct message *message);

int deserialize_message(FILE *src, struct message *message);

#endif
