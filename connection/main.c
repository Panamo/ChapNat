/*
 * In The Name Of God
 * ========================================
 * [] File Name : server.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Wed 28 Jan 2015 08:28:01 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <glib.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

	int server_port_number = atoi(argv[1]);
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
			int fd = accept_connection();

			max_socket_fd = (max_socket_fd < fd) ? fd :
			                max_socket_fd;

			struct message message;


			ulog("Message body: %s\n", message.body);
			ulog("Message verb: %s\n", message.verb);
			ulog("Message dest: %s\n", message.dest_id);
			ulog("Message src : %s\n", message.src_id);

			command_dispatcher(fd, &message);

		}
		for (i = 0; i < get_socket_size(); i++) {
			if (FD_ISSET(*get_socket(i), &socket_fds_set)) {
				struct message message;

				/* initiate message struct for when errors occurred ... */
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
						message.dest_id);
					ulog("Message src : %s\n",
						message.src_id);
					command_dispatcher(*get_socket(i),
						&message);
				}
			}
		}
	}
}
