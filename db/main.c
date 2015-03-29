/*
 * In The Name Of God
 * ========================================
 * [] File Name : server.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Sun 29 Mar 2015 10:39:02 AM IRDT
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
#include <signal.h>

#include "../common/chmessage.h"
#include "../common/chevent.h"
#include "../common/chsession.h"

#include "message.h"
#include "net.h"
#include "common.h"
#include "events.h"

struct chsession *session;
int lock;

static void sigterm_handler(int signumber, siginfo_t* info,
		void* pointer)
{
	printf("Releasing resources...\n");

	while (lock);
	events_clear(session);
	exit(0);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		udie("usage : server_port_number");


	int server_port_number = atoi(argv[1]);
	struct sigaction sigterm;
	
	memset(&sigterm, 0, sizeof(sigterm));
	sigterm.sa_sigaction = sigterm_handler;
	sigaction(SIGTERM, &sigterm, NULL);
	sigaction(SIGKILL, &sigterm, NULL);
	sigaction(SIGINT, &sigterm, NULL);

	net_init(server_port_number);
	session = events_init();

	while (1) {
		int fd;
		struct message message;

		lock = 0;
		fd = accept_connection();
		lock = 1;
		if (recv_message(&message, fd) <= 0)
			close(fd);

		int* user_data;

		user_data = malloc(sizeof(int));
		*user_data = fd;
		chsession_dispatch(session, message.verb,
				(struct chmessage *) &message, user_data);	
		free(user_data);
		close(fd);
	}
}
