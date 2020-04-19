// htab_free.c
// Brief: IJC-DU2, part 2)
// Date: 19.4.2020
// Author: Peter Urgoš - xurgos00, FIT VUT Brno

#include "htab_internal.h"

void htab_free(htab_t * t)
{
    htab_clear(t);
    free((void *)t);
}
