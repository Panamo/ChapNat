/*
 * In The Name Of God
 * ========================================
 * [] File Name : server.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Tue Jan 27 18:59:50 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <string.h>

#include "message.h"
#include "net.h"
#include "common.h"
#include "users.h"
#include "command.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
		udie("usage : server_port_number");

	int server_port_number = atoi(argv[1]);
	int server_socket_fd = net_init(server_port_number);
	int socket_fds[MAX_CONN];
	int number = 0;
	int max_socket_fd = server_socket_fd;

	init_user();

	while (1) {
		int i = 0;
		fd_set socket_fds_set;

		FD_ZERO(&socket_fds_set);
		FD_SET(server_socket_fd, &socket_fds_set);
		for (i = 0; i < number; i++)
			FD_SET(socket_fds[i], &socket_fds_set);

		if (select(max_socket_fd + 1, &socket_fds_set,
					NULL, NULL, NULL) < 0)
			sdie("select");

		if (FD_ISSET(server_socket_fd, &socket_fds_set)) {
			int fd = accept_connection();

			socket_fds[number] = fd;
			number++;
			if (max_socket_fd < fd)
				max_socket_fd = fd;
		}
		for (i = 0; i < number; i++) {
			if (FD_ISSET(socket_fds[i], &socket_fds_set)) {
				struct message message;

				if (recv_message(&message,
							socket_fds[i]) <= 0) {
					close(socket_fds[i]);
					number--;
					if (number > 0)
						socket_fds[i] =
							socket_fds[number];
					continue;
				}

				ulog("Message body: %s\n", message.body);
				ulog("Message verb: %s\n", message.verb);
				ulog("Message dest: %s\n", message.dest_id);
				ulog("Message src : %s\n", message.src_id);
				command_dispatcher(socket_fds[i], &message);
			}
		}
	}
}
