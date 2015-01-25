/*
 * In The Name Of God
 * ========================================
 * [] File Name : chobj.h
 *
 * [] Creation Date : 25-01-2015
 *
 * [] Last Modified : Sun Jan 25 08:30:17 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/

struct chobj {
	int is_group;
	char id[255];
	chobj *next;

	int fd;
	struct sockaddr_in client_addr;
};
