/*
 * In The Name Of God
 * ========================================
 * [] File Name : server.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Fri 27 Mar 2015 01:00:35 AM IRDT
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

#include "../common/chmessage.h"
#include "../common/chevent.h"
#include "../common/chsession.h"

#include "message.h"
#include "net.h"
#include "common.h"
#include "events.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
		udie("usage : server_port_number");

	int server_port_number = atoi(argv[1]);
	struct chsession *session;

	net_init(server_port_number);
	session = events_init();

	while (1) {
		int fd;
		struct message message;

		fd = accept_connection();
		if (recv_message(&message, fd) <= 0)
			close(fd);

		int* user_data;

		user_data = malloc(sizeof(int));
		*user_data = fd;
		chsession_dispatch(session, message.verb, &message, user_data);	
		free(user_data);
		close(fd);
	}
}
