/*
 * In The Name Of God
 * ========================================
 * [] File Name : message.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Wed 31 Dec 2014 01:23:16 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef MESSAGE_H
#define MESSAGE_H

#define MESSAGE_SIZE (255 * 4 + 32)

/*
 * message struct size must be less than
 * 4 * 255 byte
 * @verb: send join leave
 * @arg:
 * if verb has no argument it must be " "
 * @group_id:
 * if verb has no group id it must be -1
 * @client_name: username of client
 * +------------+------------+-------------+------------+
 * |
 * |
 * |
 * +------------+------------+-------------+------------+
*/

typedef struct{
	char verb[255];
	char arg[255];
	int group_id;
	char client_name[255];
} Message;

int serialize_message(char *buffer, const Message *message);

int deserialize_message(char *buffer, Message *message);

#endif
