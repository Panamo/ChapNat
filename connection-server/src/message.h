/*
 * In The Name Of God
 * ========================================
 * [] File Name : message.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Sat 24 Jan 2015 06:24:57 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef MESSAGE_H
#define MESSAGE_H

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
	char verb[5];
	char dest_id[255];
	char src_id[255];
	int m_size;
	char *body;
};

int serialize_message(FILE *dest, const struct message *message);

int deserialize_message(FILE *src, struct message *message);

#endif
