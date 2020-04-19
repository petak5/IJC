// htab_clear.c
// Brief: IJC-DU2, part 2)
// Date: 19.4.2020
// Author: Peter Urgoš - xurgos00, FIT VUT Brno

#include "htab_internal.h"

void htab_clear(htab_t * t)
{
    for (size_t i = 0; i < htab_bucket_count(t); i++)
    {
        if (t->items[i] == NULL)
        {
            continue;
        }

        struct htab_item *item = t->items[i];
        struct htab_item *temp = NULL;

        while (item->next != NULL)
        {
            temp = item->next;
            
            free((void *)item->key);
            free((void *)item);

            item = temp;
        }

        free((void *)item->key);
        free((void *)item);
    }
}
