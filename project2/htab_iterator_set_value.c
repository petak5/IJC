#include "htab_internal.h"

htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val)
{
    it.ptr->value = val;

    return it.ptr->value;
}
