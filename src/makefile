UNAME = $(shell uname)

OBJS = main.o ReadWriteFile.o Simulation.o MyGlut.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pthread
LFLAGS = -Wall $(DEBUG) -lm

SOURCES = main.cpp Simulation.cpp ReadWriteFile.cpp MyGlut.cpp

HEADERS = Simulation.h ReadWriteFile.h MyGlut.h

all: gorobot

gorobot: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o gorobot

main.o : main.cpp Simulation.cpp
	$(CC) $(CFLAGS)  main.cpp -o main.o

Simulation.o : Simulation.cpp
	$(CC) $(CFLAGS) Simulation.cpp -o Simulation.o

ReadWriteFile.o : ReadWriteFile.cpp
	$(CC) $(CFLAGS) ReadWriteFile.cpp -o ReadWriteFile.o

MyGlut.o : MyGlut.cpp
	$(CC) $(CFLAGS) MyGlut.cpp -o MyGlut.o

clean: 
	\rm -f $(OBJS) gorobot Project.tar *.o

rebuild:
	clear
	make clean
	make	

tar:
	tar cfv Project.tar makefile $(HEADERS) $(SOURCES)

