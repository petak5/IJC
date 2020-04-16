#include "htab_internal.h"

// konstruktor tabulky
htab_t *htab_init(size_t n)
{
    htab_t *htab = (htab_t *)malloc(sizeof(htab_t) + n * sizeof(struct htab_item *));
    if (htab == NULL)
    {
        return NULL;
    }

    htab->size = 0;
    htab->arr_size = n;

    for (size_t i = 0; i < n; i++)
    {
        htab->items[i] = NULL;
    }

    return htab;
}
