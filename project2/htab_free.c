#include "htab_internal.h"

void htab_free(htab_t * t)
{
    htab_clear(t);
    free((void *)t);
}
