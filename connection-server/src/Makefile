OBJ=main.o common.o message.o net.o error_functions.o
CFLAGS=-Wall -g

Chapat: $(OBJ)
	gcc $(CFLAGS) -o Chapat $(OBJ)
main.o: common.h net.h message.h
common.o: common.h
message.o: message.h
net.o: net.h common.h message.h error_functions.h
error_functions.o:

.PHONY: clean
clean:
	rm Chapat $(OBJ)
.PHONY: install
install:
	${MAKE} Chapat
	cp Chapat.sh /etc/init.d/ChatHub-C
	cp Chapat /usr/sbin/

