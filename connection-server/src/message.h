/*
 * In The Name Of God
 * ========================================
 * [] File Name : message.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Sat Jan 24 02:24:33 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef MESSAGE_H
#define MESSAGE_H

#define MESSAGE_SIZE (255 * 4 + 32)

/*
 * message header struct size must be less than
 * 4 * 255 byte
 * @verb: send join leave
 *
 * @group_id: if verb has no group id it must be -1
 *
 * @client_name: username of client
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

typedef struct{
	char verb[255];
	int group_id;
	char client_name[255];
	int m_size;
} Message;

int serialize_message(char *buffer, const Message *message);

int deserialize_message(char *buffer, Message *message);

#endif
