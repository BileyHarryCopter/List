CC=gcc
CFLAGS=-c -Wall
CSOURCES= sources/

all: start clean

start: list.o dump.o main.o
	$(CC) list.o dump.o main.o -o start

list.o: list.c
	$(CC) $(CFLAGS) list.c

dump.o: dump.c
	$(CC) $(CFLAGS) dump.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

run:
	./start

leaks:
	leaks -atExit -- ./start

clean:
	rm -rf *.o
