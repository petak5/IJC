#include <stdio.h>

#include "htab.h"

#define BUCKETS 1023

int main()
{
    htab_t *htab = htab_init(BUCKETS);
    if (htab == NULL)
    {
        fprintf(stderr, "An error occured.\n");
        return 1;
    }

    // todo: implement reading (safe reading!)

    for (htab_iterator_t iterator = htab_begin(htab); !htab_iterator_equal(iterator, htab_end(htab)); iterator = htab_iterator_next(iterator))
    {
        printf("%s\t%d\n", htab_iterator_get_key(iterator), htab_iterator_get_value(iterator));
    }

    return htab_hash_fun("Hello, World!");
}
