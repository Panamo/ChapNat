/*
 * In The Name Of God
 * ========================================
 * [] File Name : net.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef SERVER_NET_H
#define SERVER_NET_H

int net_init(uint16_t server_port_number);

int accept_connection(void);

int send_message(const struct message *message, int socket_fd);

int recv_message(struct message *message, int socket_fd);

#endif
