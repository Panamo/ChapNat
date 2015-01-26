/*
 * In The Name Of God
 * ========================================
 * [] File Name : server.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Mon Jan 26 14:13:14 2015
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
#include "error_functions.h"
#include "common.h"

static void skeleton_daemon(void);

int main(int argc, char *argv[])
{
	if (argc < 2)
		udie("usage : server_port_number");

	int server_port_number = atoi(argv[1]);

	//skeleton_daemon();

	int server_socket_fd = net_init(server_port_number);

	int socket_fds[MAX_CONN];
	int number = 0;
	int max_socket_fd = server_socket_fd;

	while (1) {
		int i = 0;

		fd_set socket_fds_set;
		FD_ZERO(&socket_fds_set);
		FD_SET(server_socket_fd, &socket_fds_set);
		for (i = 0; i < number; i++) {
			FD_SET(socket_fds[i], &socket_fds_set);
		}

		if (select(max_socket_fd + 1, &socket_fds_set, NULL, NULL, NULL) < 0)
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
				if (recv_message(&message, socket_fds[i]) <= 0) {
					close(socket_fds[i]);
					number--;
					if (number > 0)
						socket_fds[i] = socket_fds[number];
					continue;
				}

				printf("%s\n", message.body);
				printf("%s\n", message.verb);
				printf("%s\n", message.dest_id);
				printf("%s\n", message.src_id);
				//command_dispatcher(socket_fds[i], &message);
			}
		}

	}

}

static void skeleton_daemon(void)
{
	pid_t pid;

	/* Fork off the parent process */
	pid = fork();

	/* An error occurred */
	if (pid < 0)
		exit(EXIT_FAILURE);

	/* Success: Let the parent terminate */
	if (pid > 0)
		exit(EXIT_SUCCESS);

	/* On success: The child process becomes session leader */
	if (setsid() < 0)
		exit(EXIT_FAILURE);

	/* Fork off for the second time*/
	pid = fork();

	/* An error occurred */
	if (pid < 0)
		exit(EXIT_FAILURE);

	/* Success: Let the parent terminate */
	if (pid > 0)
		exit(EXIT_SUCCESS);

	/* Set new file permissions */
	umask(0);

	/* Change the working directory to the root directory */
	/* or another appropriated directory */
	chdir("/");

	/* Close all open file descriptors */
	printf("IN CASE OF ERROR KILL PID %ld\n", getpid());
	int x;
	for (x = sysconf(_SC_OPEN_MAX); x > 0; x--) {
		close (x);
	}

	open_log_file();
}
