#ifndef HTAB_INTERNAL
#define HTAB_INTERNAL

#include <stdlib.h>

#include "htab.h"

struct htab {
    struct htab_item **items;
    //...
};

#endif