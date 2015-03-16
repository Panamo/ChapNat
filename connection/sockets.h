/*
 * In The Name Of God
 * ========================================
 * [] File Name : sockets.h
 *
 * [] Creation Date : 28-01-2015
 *
 * [] Last Modified : Wed Jan 28 15:24:23 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef SOCKETS_H
#define SOCKETS_H

extern GSList *socket_fds;

void add_socket(int *fd);

void del_socket(int *fd);

int *get_socket(int index);

int get_socket_size(void);

#endif
