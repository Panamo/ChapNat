/*
 * In The Name Of God
 * ========================================
 * [] File Name : message.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Thu 19 Mar 2015 11:47:57 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
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

int serialize_message(FILE *dest, const struct message *message);

int deserialize_message(FILE *src, struct message *message);

#endif
