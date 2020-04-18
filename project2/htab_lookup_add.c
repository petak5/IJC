#include "htab_internal.h"

htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key)
{
    htab_iterator_t iterator = htab_find(t, key);
    
    if (!htab_iterator_equal(iterator, htab_end(t)))
    {
        return iterator;
    }

    struct htab_item *item = (struct htab_item *)malloc(sizeof(struct htab_item));

    size_t key_length = strlen(key);
    char *copy = (char *)malloc(key_length + 1);
    if (copy == NULL)
    {
        return htab_end(t);
    }
    strcpy(copy, key);

    item->key = copy;
    item->value = 0;
    item->next = NULL;

    t->size++;

    iterator.t = t;
    iterator.idx = htab_hash_fun(copy) % htab_bucket_count(t);
    iterator.ptr = iterator.t->items[iterator.idx];

    if (iterator.ptr == NULL)
    {
        // this is where we use the fact that `t` is not const pointer
        // we can't use `iterator.t`
        t->items[iterator.idx] = item;
        iterator.ptr = iterator.t->items[iterator.idx];

        return iterator;
    }

    while (iterator.ptr->next != NULL)
    {
        iterator.ptr = iterator.ptr->next;
    }

    iterator.ptr->next = item;
    iterator.ptr = iterator.ptr->next;

    return iterator;
}
