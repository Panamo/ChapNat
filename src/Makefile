OBJ=main.o
CFLAGS=-Wall

Chapat:
	gcc $(CFLAGS) -o Chapat $(OBJ)
main.o:
	gcc $(CFLAGS) -c main.c
.PHONY: clean
clean:
	rm Chapat $(OBJ)
.PHONY: install
install:
	${MAKE} Chapat
	cp Chapat.sh /etc/init.d/ChatHub-C
	cp Chapat /usr/sbin/

