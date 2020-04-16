#include "htab_internal.h"

htab_value_t htab_iterator_get_value(htab_iterator_t it)
{
    return it.ptr->value;
}
