CC=gcc
CFLAGS=-O3 -g -Wall
OBJS=obj/Matrix.o obj/MatrixOperations.o obj/MatrixGeneration.o obj/FileIO.o obj/test_Matrix.o obj/Debug.o
EXECUTABLE=build
LIBS=-lm

all: $(OBJS)
	$(CC) -o $(EXECUTABLE) $(OBJS) $(LIBS)

obj/Matrix.o:
	$(CC) -c src/Matrix.c
	mv Matrix.o obj

obj/MatrixOperations.o:
	$(CC) -c src/MatrixOperations.c
	mv MatrixOperations.o obj

obj/MatrixGeneration.o:
	$(CC) -c src/MatrixGeneration.c
	mv MatrixGeneration.o obj

obj/FileIO.o:
	$(CC) -c src/FileIO.c
	mv FileIO.o obj

obj/test_Matrix.o:
	$(CC) -c tests/test_Matrix.c
	mv test_Matrix.o obj

obj/Debug.o:
	$(CC) -c src/Debug.c
	mv Debug.o obj

clean:
	rm -f build obj/* outputs/*
