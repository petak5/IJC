CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -O2

all: tail

tail: tail.o
	$(CC) $(CFLAGS) tail.o -o tail

tail.o: tail.c
	$(CC) $(CFLAGS) -c tail.c -o tail.o

clean:
	rm *.o

zip:
	zip xurgos00.zip *.c *.cc *.h Makefile
