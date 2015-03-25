/*
 * In The Name Of God
 * ========================================
 * [] File Name : events.h
 *
 * [] Creation Date : 26-03-2015
 *
 * [] Last Modified : Thu 26 Mar 2015 02:56:14 AM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef EVENTS_H
#define EVENTS_H

void sgin_handler(const struct chmessage *message, const void *socket_fd);

void sgup_handler(const struct chmessage *message, const void *socket_fd);

void newg_handler(const struct chmessage *message, const void *socket_fd);

#endif
