CC=gcc
CFLAGS=-std=c11 -pedantic -Wall -Wextra -O0
LDFLAGS=-lm

all: primes primes-i steg-decode

primes: primes.o eratosthenes.o error.o
	$(CC) $(CFLAGS) $(LDFLAGS) primes.o eratosthenes.o error.o -o primes

primes-i: primes-i.o eratosthenes.o error.o
	$(CC) $(CFLAGS) $(LDFLAGS) primes-i.o eratosthenes.o error.o -o primes-i

primes.o: primes.c bitset.h error.h
	$(CC) $(CFLAGS) -c primes.c -o primes.o

primes-i.o: primes.c bitset.h error.h
	$(CC) $(CFLAGS) -c -DUSE_INLINE primes.c -o primes-i.o

eratosthenes.o: eratosthenes.c bitset.h error.h
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c -o error.o

steg-decode: steg-decode.o ppm.o eratosthenes.o error.o
	$(CC) $(CFLAGS) $(LDFLAGS) steg-decode.o ppm.o eratosthenes.o error.o -o steg-decode

steg-decode.o: steg-decode.c ppm.h error.h
	$(CC) $(CFLAGS) -c steg-decode.c -o steg-decode.o

ppm.o: ppm.c ppm.h error.h
	$(CC) $(CFLAGS) -c ppm.c -o ppm.o

run: primes primes-i
	./primes
	./primes-i

clean:
	rm *.o

zip:
	zip xurgos00.zip *.c *.h Makefile
