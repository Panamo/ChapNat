/*
 * In The Name Of God
 * ========================================
 * [] File Name : users.h
 *
 * [] Creation Date : 25-01-2015
 *
 * [] Last Modified : Sun 25 Jan 2015 06:10:32 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef USERS_H
#define USERS_H

void init_user(void);

void add_user(const struct message *message, int socket);

void del_user(const struct message *message, int socket);

void snd_user(const struct message *message, int socket);

#endif
