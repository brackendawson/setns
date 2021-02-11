CC=gcc
INC=-I /usr/include/bash -I /usr/include/bash/include
CFLAGS=-c -fPIC
LDFLAGS=--shared 

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ $^

setns.so: setns.o
	$(CC) $(LDFLAGS) $(INC) -o $@ $^
