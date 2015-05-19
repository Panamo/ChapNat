/*
 * In The Name Of God
 * ========================================
 * [] File Name : users.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef USERS_H
#define USERS_H

#include "message.h"

void init_user(void);

void add_user(const struct message *message, int socket);

void del_user(const char *id);

void snd_user(const struct message *message, int socket);

#endif
