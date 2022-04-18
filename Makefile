CC=gcc
CFLAGS=-c #-Wall # -Werror -Wextra
LISTSRC= sources/list
DUMPSRC= sources/dump
LOGSRC = sources/myassert

all: start clean

start: list.o dump.o log.o main.o
	$(CC) list.o dump.o log.o main.o -o start

list.o:
	$(CC) $(CFLAGS) $(LISTSRC)/list.c

dump.o:
	$(CC) $(CFLAGS) $(DUMPSRC)/dump.c

log.o:
	$(CC) $(CFLAGS) $(LOGSRC)/log.c

main.o:
	$(CC) $(CFLAGS) main.c

run:
	./start

leaks:
	leaks -atExit -- ./start

clean:
	rm -rf *.o
