#include "htab_internal.h"

htab_iterator_t htab_find(htab_t * t, htab_key_t key)
{
    htab_iterator_t iterator;
    iterator.t = t;
    iterator.idx = htab_hash_fun(key) % htab_bucket_count(t);
    iterator.ptr = iterator.t->items[iterator.idx];

    if (iterator.ptr == NULL)
    {
        return htab_end(t);
    }

    do
    {
        if (strcmp(htab_iterator_get_key(iterator), key) == 0)
        {
            return iterator;
        }

        iterator.ptr = iterator.ptr->next;

    } while (iterator.ptr != NULL);

    return htab_end(t);
}
