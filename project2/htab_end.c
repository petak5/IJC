// htab_end.c
// Brief: IJC-DU2, part 2)
// Date: 19.4.2020
// Author: Peter Urgoš - xurgos00, FIT VUT Brno

#include "htab_internal.h"

htab_iterator_t htab_end(const htab_t * t)
{
    htab_iterator_t iterator;

    iterator.ptr = NULL;
    iterator.t = t;
    iterator.idx = htab_bucket_count(t);

    return iterator;
}
