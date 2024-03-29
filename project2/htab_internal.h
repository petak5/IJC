// htab_internal.h
// Brief: IJC-DU2, part 2)
// Date: 19.4.2020
// Author: Peter Urgoš - xurgos00, FIT VUT Brno

#ifndef __HTAB_INTERNAL__
#define __HTAB_INTERNAL__

#include <stdlib.h>     // malloc and free
#include <stdint.h>     // uint32_t

#include "htab.h"

struct htab
{
    size_t size;
    size_t arr_size;
    struct htab_item *items[];
};

struct htab_item
{
    htab_key_t key;
    htab_value_t value;
    struct htab_item *next;
};

#endif // __HTAB_INTERNAL__
