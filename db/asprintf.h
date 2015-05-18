/*
 * In The Name Of God
 * ========================================
 * [] File Name : asprintf.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef ASPRINTF_H
#define ASPRINTF_H

/*
 * __printf(string-index, first-to-check)
 * is preferred over
 * __attribute__((format(printf, string-index, first-to-check)))
*/

int asprintf(char **str, const char *fmt, ...)
	__attribute__((format(printf, 2, 3)));


#endif
