// htab_erase.c
// Brief: IJC-DU2, part 2)
// Date: 19.4.2020
// Author: Peter Urgoš - xurgos00, FIT VUT Brno

#include "htab_internal.h"

void htab_erase(htab_t * t, htab_iterator_t it)
{
    htab_iterator_t iterator;
    iterator.t = it.t;
    iterator.idx = it.idx;
    iterator.ptr = iterator.t->items[iterator.idx];

    if (htab_iterator_equal(iterator, it))
    {
        struct htab_item *temp = iterator.ptr->next;
        free((void *)iterator.ptr->key);
        free((void *)iterator.ptr);
        t->items[iterator.idx] = temp;

        return;
    }

    struct htab_item *previous_item = NULL;
    while (!htab_iterator_equal(iterator, it))
    {
        previous_item = iterator.ptr;
        iterator.ptr = iterator.ptr->next;
    }

    previous_item->next = iterator.ptr->next;
    free((void *)iterator.ptr->key);
    free((void *)iterator.ptr);

    return;
}
