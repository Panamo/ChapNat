/*
 * In The Name Of God
 * ========================================
 * [] File Name : server.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Tue 30 Dec 2014 11:31:05 PM IRST
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

#include "server_net.h"
#include "error_functions.h"
#include "constants.h"
#include "command.h"

static void skeleton_daemon();

int main(int argc, char* argv[]){

	printf("Gnomovision version 69, Copyright (C) 2014 Parham Alvani (parham.alvani@gmail.com)\n");
	printf("Gnomovision comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n");
	printf("This is free software, and you are welcome to redistribute it\n");
	printf("under certain conditions; type `show c' for details.\n");
	printf("\n");

	if(argc < 2){
		use_die("usage : server server_ip_address server_port_number");
	}
	
	server_port_number = atoi(argv[1]);

	skeleton_daemon();
	
	int server_socket_fd = net_init();
	
	int socket_fds[MAX_CONN];
	int number = 0;
	int max_socket_fd = server_socket_fd;

	while(1){
		int i = 0;

		fd_set socket_fds_set;
		FD_ZERO(&socket_fds_set);
		FD_SET(server_socket_fd, &socket_fds_set);
		for(i = 0; i < number; i++){
			FD_SET(socket_fds[i], &socket_fds_set);
		}

		if(select(max_socket_fd + 1, &socket_fds_set, NULL, NULL, NULL) < 0){
			log_error("select");
		}

		if(FD_ISSET(server_socket_fd, &socket_fds_set)){
			int fd = accept_connection();	
			socket_fds[number] = fd;
			number++;
			if(max_socket_fd < fd){
				max_socket_fd = fd;
			}
		}
		for(i = 0; i < number; i++){
			if(FD_ISSET(socket_fds[i], &socket_fds_set)){
				Message message;
				if(recv_message(&message, socket_fds[i]) <= 0){
					close(socket_fds[i]);
					number--;
					if(number > 0){
						socket_fds[i] = socket_fds[number];
					}
					continue;
				}

				command_dispatcher(socket_fds[i], &message);
			}
		}
		 
	}

}

static void skeleton_daemon(){
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
	for (x = sysconf(_SC_OPEN_MAX); x > 0; x--){
		close (x);
	}
	
	open_log_file();
}
