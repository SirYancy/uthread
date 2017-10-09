CXX = g++
CC = gcc

OBJECTS = tcb.o uthread.o

default: main

tcb: tcb.h tcb.cpp
	$(CXX) -c tcb.cpp

uthread: uthread.h uthread.cpp
	$(CXX) -c uthread.cpp

main: $(OBJECTS)
	$(CXX) main.cpp $(OBJECTS) -o main
	

clean:
	rm -f *.o *.exe a.out main
