# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 16-03-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=Chapat-db
OBJ=main.o common.o command.o net.o message.o users.o \
    asprintf.o
LIB=
MLIB=

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=$(MLIB)
endif
ASFLAGS=-Wall -O0 -g
CFLAGS+=-DDEBUG

$(P): $(OBJ)
	$(CC) -o $(P) $(OBJ) $(LDLIBS)
main.o:
common.o: common.h
command.o: command.h users.h
net.o: net.h
message.o: message.h
users.o: users.h
asprintf.o: asprintf.h

.PHONY: clean
clean:
	rm $(OBJ) $(P)
