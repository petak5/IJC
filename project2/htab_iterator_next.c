#include "htab_internal.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it)
{
    if (htab_iterator_equal(it, htab_end(it.t)))
    {
        return htab_end(it.t);
    }

    if (it.ptr->next != NULL)
    {
        it.ptr = it.ptr->next;
        return it;
    }

    for (size_t i = it.idx + 1; i < htab_bucket_count(it.t); i++)
    {
        if (it.t->items[i] != NULL)
        {
            it.ptr = it.t->items[i];
            it.idx = i;

            return it;
        }
    }

    return htab_end(it.t);
}
