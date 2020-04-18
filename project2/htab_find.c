#include "htab_internal.h"

htab_iterator_t htab_find(htab_t * t, htab_key_t key)
{
    htab_iterator_t iterator = htab_begin(t);

    while (!htab_iterator_equal(iterator, htab_end(t)))
    {
        if (strcmp(iterator.ptr->key, key) == 0)
        {
            return iterator;
        }

        iterator = htab_iterator_next(iterator);
    }

    return htab_end(t);
}
