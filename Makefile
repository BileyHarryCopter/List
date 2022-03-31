CC=gcc
CFLAGS=-c #-Wall # -Werror -Wextra
LISTSRC= sources/list
DUMPSRC= sources/dump

all: start clean

start: list.o dump.o main.o
	$(CC) list.o dump.o main.o -o start

list.o:
	$(CC) $(CFLAGS) $(LISTSRC)/list.c

dump.o:
	$(CC) $(CFLAGS) $(DUMPSRC)/dump.c

main.o:
	$(CC) $(CFLAGS) main.c

run:
	./start

leaks:
	leaks -atExit -- ./start

clean:
	rm -rf *.o
