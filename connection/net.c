/*
 * In The Name Of God
 * ========================================
 * [] File Name : net.c
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "message.h"
#include "net.h"
#include "common.h"

static int server_socket_fd;

int net_init(uint16_t server_port_number)
{
	struct sockaddr_in server_addr;

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(server_port_number);

	server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket_fd == -1)
		sdie("socket()");

	if (bind(server_socket_fd, (struct sockaddr *) &server_addr,
		sizeof(server_addr)) == -1)
		sdie("bind()");

	if (listen(server_socket_fd, 10) == -1)
		sdie("listen()");

	return server_socket_fd;
}

int accept_connection(void)
{
	return accept(server_socket_fd, NULL, NULL);
}

int send_message(const struct message *message, int socket_fd)
{
	FILE *socket_file = fdopen(socket_fd, "r+");

	if (socket_file == NULL)
		slog("fdopen()");

	return message_serialize(socket_file, message);
}

int recv_message(struct message *message, int socket_fd)
{
	FILE *socket_file = fdopen(socket_fd, "r+");

	if (socket_file == NULL)
		slog("fdopen()");

	return message_deserialize(socket_file, message);
}
