/*
 * In The Name Of God
 * ========================================
 * [] File Name : message.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Sat Jan 24 03:05:57 2015
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
 * @verb: send join leave
 *
 * @group_id: if verb has no group id it must be -1
 *
 * @client_name: uuid of client
 *
 * @size: sizeof message body in bytes
 *
 * +------------+------------+-------------+------------+
 * |    verb    |  group_id  | client_name |     size   |
 * +------------+------------+-------------+------------+
 * |                                                    |
 * |                  Message Body                      |
 * |                                                    |
 * +----------------------------------------------------+
*/

struct message {
	char verb[5];
	int group_id;
	char client_name[255];
	int m_size;
	char *body;
};

int serialize_message(FILE *dest, const struct message *message);

int deserialize_message(FILE *src, struct message *message);

#endif
