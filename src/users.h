/*
 * In The Name Of God
 * ========================================
 * [] File Name : users.h
 *
 * [] Creation Date : 25-01-2015
 *
 * [] Last Modified : Wed Jan 28 15:35:45 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef USERS_H
#define USERS_H

void init_user(void);

void add_user(const struct message *message, int socket);

void del_user(const char *id);

void snd_user(const struct message *message, int socket);

#endif
