/*
 * In The Name Of God
 * ========================================
 * [] File Name : server_net.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Tue 30 Dec 2014 11:31:05 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#include "server_net.h"
#include "constants.h"
#include "error_functions.h"
#include "message.h"

int server_socket_fd;

int net_init(){

	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(server_port_number);

	server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_socket_fd == -1){
		error_die("socket()");
	}
 
	if(bind(server_socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1){
		error_die("bind()");
	}
	
	if(listen(server_socket_fd, 10) == -1){
		error_die("listen()");
	}
	
	return server_socket_fd;
}

int accept_connection(){
	return accept(server_socket_fd, NULL, NULL);
}

int send_message(Message* message, int socket_fd){
	char buffer[MAX_BUFF];

	serialize_message(buffer, message);
	
	return send(socket_fd, buffer, strlen(buffer), 0);
}

int recv_message(Message* message, int socket_fd){
	char buffer[MAX_BUFF];

	FILE* socket_file = fdopen(socket_fd, "r+");
	if(socket_file == NULL){
		log_error("fdopen()");
	}

	if(fgets(buffer, MAX_BUFF, socket_file) == NULL){
		return 0;
	}

	deserialize_message(buffer, message);

	return strlen(buffer);
}

