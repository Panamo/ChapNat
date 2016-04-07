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

#define MESSAGE_SIZE (255 * 4 + 32)

/*
 * message header fields must be separate with ' ', and
 * connection created over TCP so field sequence is important
 *
 * +------------+--------------------------+------------+
 * |    verb    |   user_id  |     pass    |    user    |
 * +------------+--------------------------+------------+
*/

struct message {
	char verb[10];
	char user_id[255];
	char user[255];
	char pass[255];
};

int message_serialize(FILE *dst, const struct message *message);

int message_deserialize(FILE *src, struct message *message);

#endif
