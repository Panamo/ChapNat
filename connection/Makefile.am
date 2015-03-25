AM_CFLAGS = -Wall -O0 -g -std=gnu11

bin_PROGRAMS = chapat
chapat_SOURCES = chdef.h chobj.c chobj.h command.c command.h common.c common.h main.c message.c \
		 message.h net.c net.h resolve.c resolve.h sockets.c sockets.h users.c users.h
chapat_CFLAGS = $(AM_CFLAGS) -pthread -I/usr/local/include/libsoup-2.4 -I/usr/local/include/glib-2.0 \
		-I/usr/local/lib/glib-2.0/include -I/usr/include/libxml2
chapat_LDADD = -lsoup-2.4 -lgio-2.0 -lgobject-2.0 -lglib-2.0
chapat_LDFLAGS = -L/usr/local/lib
