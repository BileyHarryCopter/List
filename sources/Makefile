CC=gcc
CFLAGS=-c -Wall
CSOURCES= sources/

all: start clean

start: List.o main.o
	$(CC) List.o main.o -o start

List.o: List.c
	$(CC) $(CFLAGS) List.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *.o
