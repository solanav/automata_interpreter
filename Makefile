SRC=src/
INCLUDE=include/

EXEC_NAME=mach

CC=gcc
CFLAGS=-g -Wall
LIBS=-lm

all: $(EXEC_NAME)

$(EXEC_NAME): main.o trans.o state.o machine.o
	$(CC) -o $@ $^ $(CFLAGS)

main.o: $(SRC)main.c $(INCLUDE)types.h $(INCLUDE)trans.h $(INCLUDE)state.h $(INCLUDE)machine.h
	$(CC) -c -o $@ $< $(CFLAGS)

trans.o: $(SRC)trans.c $(INCLUDE)types.h $(INCLUDE)trans.h
	$(CC) -c -o $@ $< $(CFLAGS)

state.o: $(SRC)state.c $(INCLUDE)types.h $(INCLUDE)state.h
	$(CC) -c -o $@ $< $(CFLAGS)

machine.o: $(SRC)machine.c $(INCLUDE)types.h $(INCLUDE)machine.h
	$(CC) -c -o $@ $< $(CFLAGS)

valgrind:
	valgrind --leak-check=full -v ./$(EXEC_NAME)

clean:
	rm *.o $(EXEC_NAME)
