#include "htab_internal.h"

htab_iterator_t htab_begin(const htab_t * t)
{
    htab_iterator_t iterator;
    iterator.ptr = t->items[0];
    iterator.t = t;
    iterator.idx = 0;

    while (!htab_iterator_valid(iterator))
    {
        iterator = htab_iterator_next(iterator);

        if (htab_iterator_equal(iterator, htab_end(t)))
        {
            break;
        }
    }

    return iterator;
}
