// htab_bucket_count.c
// Brief: IJC-DU2, part 2)
// Date: 19.4.2020
// Author: Peter Urgoš - xurgos00, FIT VUT Brno

#include "htab_internal.h"

size_t htab_bucket_count(const htab_t * t)
{
    return t->arr_size;
}
