CC=gcc
CFLAGS=-std=c11 -pedantic -Wall -Wextra
LDFLAGS=-lm

primes: primes.c eratosthenes.c
	$(CC) $(CFLAGS) $(LDFLAGS) primes.c eratosthenes.c -o primes
primes-i: primes.c eratosthenes.c
	$(CC) $(CFLAGS) $(LDFLAGS) -DUSE_INLINE primes.c eratosthenes.c -o primes-i
run: primes primes-i
	./primes
	./primes-i
