/*
 * In The Name Of God
 * ========================================
 * [] File Name : command.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Sun Jan 25 03:54:59 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef COMMAND_H
#define COMMAND_H

void command_dispatcher(int socket_fd, const message *message);

#endif
