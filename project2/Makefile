CC=gcc-9
CFLAGS=-std=c99 -pedantic -Wall -Wextra -O2

MODULES=htab_hash_fun.o

.PHONY: clean zip

all: tail wordcount wordcount-dynamic

tail: tail.o
	$(CC) $(CFLAGS) tail.o -o tail

tail.o: tail.c
	$(CC) $(CFLAGS) -c tail.c -o tail.o

# part 2
wordcount: wordcount.o libhtab.a
	$(CC) $(CFLAGS) $^ -o $@

wordcount-dynamic: wordcount.o libhtab.so
	$(CC) $(CFLAGS) $^ -o $@

wordcount.o: wordcount.c htab.h
	$(CC) $(CFLAGS) -c -fPIC wordcount.c -o $@

libhtab.a: $(MODULES)
	ar crs libhtab.a $^

libhtab.so: $(MODULES)
	$(CC) -shared -fPIC -L. $^ -o $@

clean:
	rm -f *.o *.a *.so

zip:
	zip xurgos00.zip *.c *.cc *.h Makefile
