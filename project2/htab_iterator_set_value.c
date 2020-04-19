// htab_iterator_set_value.c
// Brief: IJC-DU2, part 2)
// Date: 19.4.2020
// Author: Peter Urgoš - xurgos00, FIT VUT Brno

#include "htab_internal.h"

htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val)
{
    it.ptr->value = val;

    return it.ptr->value;
}
