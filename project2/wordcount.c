#include "htab.h"

#define BUCKETS 1023

int main()
{
    htab_t *htab = htab_init(BUCKETS);
    return htab_hash_fun("Hello, World!");
}
