# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 25-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

OBJ=main.o common.o message.o net.o \
    users.o chobj.o command.o sockets.o
LIB=glib-2.0
MLIB=

# Remove it when you don't want debug messages.
DEFINES=-DDEBUG

CFLAGS=-Wall -O0 -g -std=gnu11 $(DEFINES) \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)

Chapat.out: $(OBJ)
	gcc $(CFLAGS) -o Chapat.out $(OBJ) $(LDLIBS)
main.o: common.h net.h message.h
common.o: common.h
message.o: message.h common.h
net.o: net.h common.h message.h
users.o: message.h users.h net.h common.h
chobj.o: chobj.h
command.o: command.h users.h net.h message.h
sockets.o: sockets.h

.PHONY: clean
clean:
	rm Chapat.out $(OBJ)
.PHONY: install
install:
	$(MAKE) Chapat.out
	cp Chapat.sh /etc/init.d/ChatHub-C
	cp Chapat.out /usr/sbin/

