CC=gcc
CFLAGS=-std=c11 -pedantic -Wall -Wextra -O0
LDFLAGS=-lm

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

run: primes primes-i
	./primes
	./primes-i

clean:
	rm *.o

zip:
	zip xurgos00.zip *.c *.h Makefile
