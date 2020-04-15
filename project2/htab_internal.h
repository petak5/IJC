#ifndef __HTAB_INTERNAL__
#define __HTAB_INTERNAL__

#include <stdlib.h>     // uint32_t

#include "htab.h"

#define BUCKETS 1023

struct htab
{
    struct htab_item **items;
    //...
};

struct htab_item
{
    //...
};

#endif // __HTAB_INTERNAL__
