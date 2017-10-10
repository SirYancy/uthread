CXX = g++
CC = gcc
CXXFLAGS = 

OBJECTS = tcb.o uthread.o

default: main

debug: CXXFLAGS += -g -O0
debug: main

tcb: tcb.h tcb.cpp
	$(CXX) -c tcb.cpp

uthread: uthread.h uthread.cpp
	$(CXX) -c uthread.cpp

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) main.cpp $(OBJECTS) -o main
	
clean:
	rm -f *.o *.exe a.out main
