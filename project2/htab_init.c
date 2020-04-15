#include "htab_internal.h"

// konstruktor tabulky
htab_t *htab_init(size_t n)
{
    htab_t *htab = malloc(100000);
}

// temporarily store this here :)
struct htab_item *item_init(htab_key_t key)
{
    struct htab_item *item = malloc(sizeof(struct htab_item));
    return item;
}
