/*
 * In The Name Of God
 * ========================================
 * [] File Name : error_functions.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Tue 30 Dec 2014 11:31:04 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <syslog.h>

#include "error_functions.h"

int is_open = 0;

void open_log_file(){
	if(is_open == 0){
		openlog ("chat-hub-deamon", LOG_PID, LOG_DAEMON);
		is_open = 1;
	}
}

void terminate(){
	exit(EXIT_FAILURE);
}

void log_error(const char* msg){
	open_log_file();
	
	perror(msg);
	syslog(LOG_DAEMON | LOG_ERR, "%s : %m", msg);
}

void log_war(const char* msg){
	open_log_file();

	syslog(LOG_DAEMON | LOG_WARNING, "%s : %m", msg);
}

void error_die(const char* msg){
	log_error(msg);
	terminate();
}

void use_die(const char* msg){
	fprintf(stderr, "%s\n", msg);
	terminate();
}
