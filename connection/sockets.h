/*
 * In The Name Of God
 * ========================================
 * [] File Name : sockets.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef SOCKETS_H
#define SOCKETS_H

extern GSList *socket_fds;

void sockets_add(int *fd);

void sockets_delete(int *fd);

int *sockets_get(int index);

int sockets_size(void);

#endif
