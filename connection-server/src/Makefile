# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 25-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

OBJ=main.o common.o message.o net.o error_functions.o \
    users.o chobj.o command.o
LIB=glib-2.0
MLIB=

CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)

Chapat.out: $(OBJ)
	gcc $(CFLAGS) -o Chapat.out $(OBJ) $(LDLIBS)
main.o: common.h net.h message.h
common.o: common.h
message.o: message.h
net.o: net.h common.h message.h error_functions.h
error_functions.o:
users.o: message.h users.h net.h
chobj.o: chobj.h
command.o: command.h users.h net.h message.h

.PHONY: clean
clean:
	rm Chapat.out $(OBJ)
.PHONY: install
install:
	$(MAKE) Chapat.out
	cp Chapat.sh /etc/init.d/ChatHub-C
	cp Chapat.out /usr/sbin/

