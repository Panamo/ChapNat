/*
 * In The Name Of God
 * ========================================
 * [] File Name : command.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef COMMAND_H
#define COMMAND_H

void command_dispatcher(int socket_fd,
	const struct message *message);

#endif
