# Makefile
# Brief: IJC-DU2
# Date: 19.4.2020
# Author: Peter Urgoš - xurgos00, FIT VUT Brno

CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -O2 -fPIC

LD_LIBRARY_PATH='.'

MODULES=htab_begin.o htab_bucket_count.o htab_clear.o htab_end.o htab_erase.o htab_find.o htab_free.o htab_hash_fun.o htab_init.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_next.o htab_iterator_set_value.o htab_lookup_add.o htab_size.o

.PHONY: all clean zip

all: tail wordcount wordcount-dynamic

# part 1
tail: tail.o
	$(CC) $(CFLAGS) tail.o -o tail

tail.o: tail.c
	$(CC) $(CFLAGS) -c $< -o $@

# part 2
wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) $^ -o $@

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) $^ -o $@

wordcount.o: wordcount.c htab.h
	$(CC) $(CFLAGS) -c $< -o $@

io.o: io.c io.h
	$(CC) $(CFLAGS) -c $< -o $@

# libraries
libhtab.a: $(MODULES)
	ar crs libhtab.a $^

libhtab.so: $(MODULES)
	$(CC) $(CFLAGS) -shared -L$(LD_LIBRARY_PATH) $^ -o $@

# library modules
htab_begin.o: htab_begin.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_bucket_count.o: htab_bucket_count.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_clear.o: htab_clear.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_end.o: htab_end.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_erase.o: htab_erase.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_find.o: htab_find.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_free.o: htab_free.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_hash_fun.o: htab_hash_fun.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_init.o: htab_init.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_iterator_get_key.o: htab_iterator_get_key.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_iterator_get_value.o: htab_iterator_get_value.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_iterator_next.o: htab_iterator_next.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_iterator_set_value.o: htab_iterator_set_value.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_lookup_add.o: htab_lookup_add.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

htab_size.o: htab_size.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a *.so tail wordcount wordcount-dynamic

zip:
	zip xurgos00.zip *.c *.cc *.h Makefile
