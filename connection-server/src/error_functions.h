/*
 * In The Name Of God
 * ========================================
 * [] File Name : error_functions.h
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Tue 30 Dec 2014 11:31:06 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

void open_log_file();

void terminate();

void log_error(const char* msg);

void log_war(const char* msg);

void error_die(const char* msg);

void use_die(const char* msg);

#endif
