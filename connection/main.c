/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <glib.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#include "message.h"
#include "net.h"
#include "common.h"
#include "users.h"
#include "command.h"
#include "sockets.h"

static int run = 1;

int main(int argc, char *argv[])
{
	if (argc < 2)
		udie("usage : server_port_number");

	printf("Chapat version 2.0, Copyright (C) Chapna Organization\n");
	printf("Chapat comes with ABSOLUTELY NO WARRANTY\n");
	printf("This is free software, and you are welcome to redistribute it\n");
	printf("under certain conditions\n");

	uint16_t server_port_number = (uint16_t) atoi(argv[1]);
	int server_socket_fd = net_init(server_port_number);
	int max_socket_fd = server_socket_fd;

	init_user();

	while (run) {
		int i = 0;
		fd_set socket_fds_set;

		FD_ZERO(&socket_fds_set);
		FD_SET(server_socket_fd, &socket_fds_set);
		for (i = 0; i < get_socket_size(); i++)
			FD_SET(*get_socket(i), &socket_fds_set);

		if (select(max_socket_fd + 1, &socket_fds_set,
			NULL, NULL, NULL) < 0)
			sdie("select");

		if (FD_ISSET(server_socket_fd, &socket_fds_set)) {
			int *fd;

			fd = malloc(sizeof(int));

			*fd = accept_connection();

			ulog("New connection accepted.\n");

			add_socket(fd);
			max_socket_fd = (max_socket_fd < *fd) ? *fd :
			                max_socket_fd;
		}
		for (i = 0; i < get_socket_size(); i++) {
			if (FD_ISSET(*get_socket(i), &socket_fds_set)) {
				struct message message;

				/* initiate message struct */
				memset(&message, 0, sizeof(message));

				if (recv_message(&message,
					*get_socket(i)) <= 0) {

					ulog("%d socket errored\n",
						*get_socket(i));
					close(*get_socket(i));
					del_socket(get_socket(i));
				} else {
					ulog("Message body: %s\n",
						message.body);
					ulog("Message verb: %s\n",
						message.verb);
					ulog("Message dest: %s\n",
						message.dst_id);
					ulog("Message src : %s\n",
						message.src_id);
					command_dispatcher(*get_socket(i),
						&message);
				}
			}
		}
	}
	return 0;
}
