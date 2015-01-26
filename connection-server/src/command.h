/*
 * In The Name Of God
 * ========================================
 * [] File Name : command.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Mon Jan 26 18:16:26 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef COMMAND_H
#define COMMAND_H

void command_dispatcher(int socket_fd,
		const struct message *message);

#endif
