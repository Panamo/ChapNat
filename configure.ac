#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([chapat], [1.00], parham.alvani@gmail.com)
AC_CONFIG_SRCDIR([db/ src/])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lcrypto':
AC_CHECK_LIB([crypto], [])
# FIXME: Replace `main' with a function in `-lssl':
AC_CHECK_LIB([ssl], [])

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h netinet/in.h stdlib.h string.h sys/socket.h syslog.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset select socket])

AC_CONFIG_FILES([connection/Makefile
                 db/Makefile])
AC_OUTPUT
