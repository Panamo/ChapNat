/*
 * In The Name Of God
 * ========================================
 * [] File Name : users.h
 *
 * [] Creation Date : 25-01-2015
 *
 * [] Last Modified : Thu 19 Mar 2015 11:30:49 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef USERS_H
#define USERS_H

void add_user(const struct message *message, int socket);

void get_user(const struct message *message, int socket);

#endif
