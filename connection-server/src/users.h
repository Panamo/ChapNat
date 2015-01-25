/*
 * In The Name Of God
 * ========================================
 * [] File Name : users.h
 *
 * [] Creation Date : 25-01-2015
 *
 * [] Last Modified : Sun Jan 25 04:04:41 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef USERS_H
#define USERS_H

void add_user(const struct message *message, int socket);

void del_user(const struct message *message, int socket);

void snd_user(const struct message *message, int socket);

#endif
