/*
 * In The Name Of God
 * ========================================
 * [] File Name : net.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Sat Jan 24 03:45:17 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef SERVER_NET_H
#define SERVER_NET_H

int net_init(int server_port_number);

int accept_connection(void);

int send_message(const struct message *message, int socket_fd);

int recv_message(struct message *message, int socket_fd);

#endif
