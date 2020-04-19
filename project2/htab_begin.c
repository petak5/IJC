// htab_begin.c
// Brief: IJC-DU2, part 2)
// Date: 19.4.2020
// Author: Peter Urgoš - xurgos00, FIT VUT Brno

#include "htab_internal.h"

htab_iterator_t htab_begin(const htab_t * t)
{
    if (htab_size(t) == 0)
    {
        return htab_end(t);
    }

    for (size_t i = 0; i < htab_bucket_count(t); i++)
    {
        if (t->items[i] != NULL)
        {
            htab_iterator_t iterator;
            iterator.ptr = t->items[i];
            iterator.t = t;
            iterator.idx = i;

            return iterator;
        }
    }

    return htab_end(t);
}
