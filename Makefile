CC=gcc
CFLAGS=-g -Wall
LIBS=-lm

all: prog1

prog1: prog1.o
	$(CC) -o $@ $^ $(CFLAGS)

prog.o: prog.c
	$(CC) -c -o $@ $< $(CFLAGS)

valgrind:
	valgrind --leak-check=full -v ./prog1

clean:
	rm prog1.o prog1
