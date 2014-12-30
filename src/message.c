/*
 * In The Name Of God
 * ========================================
 * [] File Name : message.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Tue 30 Dec 2014 11:31:04 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

#include "message.h"

int serialize_message(char* buffer, const Message* message){
	return sprintf(buffer, "%s:%s:%d:%s\n", message->verb, message->arg, message->group_id, message->client_name);
}

int deserialize_message(char* buffer, Message* message){
	int general_index = 0;

	int special_index = 0;
	while(buffer[general_index] != ':'){
		message->verb[special_index] = buffer[general_index];
		special_index++;
		general_index++;
	}
	message->verb[special_index] = '\0';
	general_index++;
	
	special_index = 0;
	while(buffer[general_index] != ':'){
		message->arg[special_index] = buffer[general_index];
		special_index++;
		general_index++;
	}
	message->arg[special_index] = '\0';
	general_index++;

	char temp[255];
	special_index = 0;
	while(buffer[general_index] != ':'){
		temp[special_index] = buffer[general_index];
		special_index++;
		general_index++;
	}
	temp[special_index] = '\0';
	sscanf(temp, "%d", &message->group_id);
	general_index++;
	
	special_index = 0;
	while(buffer[general_index] != '\n'){
		message->client_name[special_index] = buffer[general_index];
		special_index++;
		general_index++;
	}
	message->client_name[special_index] = '\0';

	return general_index + 1;
}
