/*
 * In The Name Of God
 * ========================================
 * [] File Name : server.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Sat 21 Mar 2015 10:35:20 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
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

	net_init(server_port_number);

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
