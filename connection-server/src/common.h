/*
 * In The Name Of God
 * ========================================
 * [] File Name : common.h
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Tue Jan 27 16:23:42 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef COMMON_H
#define COMMON_H

#define MAX_BUFF (1000 * 1000)
#define MAX_CONN (1024)

void sdie(const char *fmt, ...);
void udie(const char *fmt, ...);
void ulog(const char *fmt, ...);
void slog(const char *fmt, ...);

#endif
