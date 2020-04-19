// htab_iterator_get_key.c
// Brief: IJC-DU2, part 2)
// Date: 19.4.2020
// Author: Peter Urgoš - xurgos00, FIT VUT Brno

#include "htab_internal.h"

htab_key_t htab_iterator_get_key(htab_iterator_t it)
{
    return it.ptr->key;
}
