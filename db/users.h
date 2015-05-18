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

void add_user(const struct message *message, int socket);

void get_user(const struct message *message, int socket);

#endif
