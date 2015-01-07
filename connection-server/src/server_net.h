/*
 * In The Name Of God
 * ========================================
 * [] File Name : server_net.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Tue 30 Dec 2014 11:31:07 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "message.h"

#ifndef SERVER_NET_H
#define SERVER_NET_H

int server_port_number;

int net_init();

int accept_connection();

int send_message(Message* message, int socket_fd);

int recv_message(Message* message, int socket_fd);

#endif
