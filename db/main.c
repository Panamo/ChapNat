/*
 * In The Name Of God
 * ========================================
 * [] File Name : server.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Mon 16 Mar 2015 05:26:37 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <glib.h>
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
#include "command.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
		udie("usage : server_port_number");

	int server_port_number = atoi(argv[1]);
	int server_socket_fd = net_init(server_port_number);
	int max_socket_fd = server_socket_fd;

	while (1) {
		int fd;
		struct message message;
		
		fd = accept_connection();
		if (recv_message(&message, fd) <= 0)
			close(fd);
			
		command_dispatcher(fd, &message);
		close(fd);
	}
}
