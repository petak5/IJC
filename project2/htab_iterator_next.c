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

    while (it.ptr->next == NULL)
    {
        it.idx++;
        it.ptr = it.t->items[it.idx];

        if (it.idx == htab_bucket_count(it.t))
        {
            return htab_end(it.t);
        }
    }

    return it;
}
