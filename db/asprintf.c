/*
 * In The Name Of God
 * ========================================
 * [] File Name : asprintf.c
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "asprintf.h"

int asprintf(char **str, const char *fmt, ...)
{
	va_list argp;
	int len = 0;
	/* temp array just for finding size */
	char one_char[1];

	/* finding size */
	va_start(argp, fmt);
	len = vsnprintf(one_char, 1, fmt, argp);
	if (len < 1) {
		fprintf(stderr, "An encoding error occured.");
		fprintf(stderr, "Setting the input pointer to NULL.\n");
		*str = NULL;
		return len;
	}
	va_end(argp);

	/* allocating space for string */
	*str = malloc(len + 1);

	/* printing string to allocated space */
	if (!str) {
		fprintf(stderr, "Couldn't allocate %i bytes.\n", len + 1);
		return -1;
	}
	va_start(argp, fmt);
	vsnprintf(*str, len + 1, fmt, argp);
	va_end(argp);

	return len;
}
