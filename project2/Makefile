CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -O2

LD_LIBRARY_PATH='.'

MODULES=htab_begin.o htab_bucket_count.o htab_clear.o htab_end.o htab_erase.o htab_find.o htab_free.o htab_hash_fun.o htab_init.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_next.o htab_iterator_set_value.o htab_lookup_add.o htab_size.o

.PHONY: clean zip

all: tail wordcount wordcount-dynamic

# part 1
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

# libraries
libhtab.a: $(MODULES)
	ar crs libhtab.a $^

libhtab.so: $(MODULES)
	$(CC) -shared -fPIC -L$(LD_LIBRARY_PATH) $^ -o $@

# library modules
htab_begin.o: htab_begin.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_begin.c -o $@

htab_bucket_count.o: htab_bucket_count.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_bucket_count.c -o $@

htab_clear.o: htab_clear.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_clear.c -o $@

htab_end.o: htab_end.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_end.c -o $@

htab_erase.o: htab_erase.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_erase.c -o $@

htab_find.o: htab_find.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_find.c -o $@

htab_free.o: htab_free.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_free.c -o $@

htab_hash_fun.o: htab_hash_fun.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_hash_fun.c -o $@

htab_init.o: htab_init.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_init.c -o $@

htab_iterator_get_key.o: htab_iterator_get_key.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_iterator_get_key.c -o $@

htab_iterator_get_value.o: htab_iterator_get_value.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_iterator_get_value.c -o $@

htab_iterator_next.o: htab_iterator_next.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_iterator_next.c -o $@

htab_iterator_set_value.o: htab_iterator_set_value.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_iterator_set_value.c -o $@

htab_lookup_add.o: htab_lookup_add.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_lookup_add.c -o $@

htab_size.o: htab_size.c htab_internal.h htab.h
	$(CC) $(CFLAGS) -c -fPIC htab_size.c -o $@

clean:
	rm -f *.o *.a *.so tail wordcount wordcount-dynamic

zip:
	zip xurgos00.zip *.c *.cc *.h Makefile
