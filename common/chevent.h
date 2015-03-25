/*
 * In The Name Of God
 * ========================================
 * [] File Name : chevent.h
 *
 * [] Creation Date : 25-03-2015
 *
 * [] Last Modified : Wed 25 Mar 2015 01:45:42 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef CHEVENT_H
#define CHEVENT_H

#include "chmessage.h"

struct chevent {
	void (*handler)(const struct chmessage *message,
			const void *user_data);
	
};

#endif
