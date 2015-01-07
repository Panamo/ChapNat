OBJ=main.o common.o
CFLAGS=-Wall

Chapat: $(OBJ)
	gcc $(CFLAGS) -o Chapat $(OBJ)
main.o: main.c common.h
	gcc $(CFLAGS) -c main.c
common.o: common.c common.h
	gcc $(CFLAGS) -c common.c
.PHONY: clean
clean:
	rm Chapat $(OBJ)
.PHONY: install
install:
	${MAKE} Chapat
	cp Chapat.sh /etc/init.d/ChatHub-C
	cp Chapat /usr/sbin/

