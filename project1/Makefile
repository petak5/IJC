CC=gcc
CFLAGS=-std=c11 -pedantic -Wall -Wextra
LDFLAGS=-lm

primes: primes.o eratosthenes.o
	$(CC) $(CFLAGS) $(LDFLAGS) primes.o eratosthenes.o -o primes

primes-i: primes-i.o eratosthenes.o
	$(CC) $(CFLAGS) $(LDFLAGS) primes-i.o eratosthenes.o -o primes-i

primes.o: primes.c
	$(CC) $(CFLAGS) -c primes.c -o primes.o

primes-i.o: primes.c
	$(CC) $(CFLAGS) -c -DUESE_INLINE primes.c -o primes-i.o

eratosthenes.o: eratosthenes.c
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

run: primes primes-i
	./primes
	./primes-i

clean:
	rm *.o
