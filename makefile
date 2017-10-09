CXX = g++
CC = gcc

OBJECTS = queue.o uthread.o

default: main

queue.o: queue.c
	$(CC) -c queue.c

uthread.o: uthread.h uthread.c
	$(CC) -c uthread.c

main: $(OBJECTS)
	$(CC) main.c $(OBJECTS) -o main
	

clean:
	rm -f *.o *.exe a.out main
