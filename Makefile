C = gcc
CFLAGS = -O2 --std=c18 -Wall # -Werror -Wextra
# src directories
SRCDIR  = sources
LISTDIR = $(SRCDIR)/list
DUMPDIR = $(SRCDIR)/dump
LOGDIR  = $(SRCDIR)/myassert
# h files
INCLUDE = -I./$(LISTDIR) -I./$(DUMPDIR) -I./$(LOGDIR) -I./includes

# c files
SRC  = $(LISTDIR)/list.c $(DUMPDIR)/dump.c $(LOGDIR)/log.c main.c
OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

# concat path to h files to flags
CFLAGS += $(INCLUDE)

.PHONY: all
all:
	@echo "Compling..."
	@$(C) $(CFLAGS) $(SRC) -o start

.PHONY: run	
run:
	@echo "Running the programm..."
	@./start

.PHONY: leaks
leaks:
	@echo "Running the program with mode of memleaks finding..."
	@leaks -atExit -- ./start

.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -rf *.o
