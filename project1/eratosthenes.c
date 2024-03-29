// eratosthenes.c
// Řešení IJC-DU1, příklad a), 17.3.2020
// Autor: Peter Urgoš - xurgos00, FIT VUT v Brne

#include "eratosthenes.h"

void Eratosthenes(bitset_t pole)
{
    bitset_setbit(pole, 0, 1);
    bitset_setbit(pole, 1, 1);

    unsigned long size = bitset_size(pole);

    for (unsigned long i = 2; i < sqrt(size); i++)
    {
        if (bitset_getbit(pole, i) == 0)
        {
            for (unsigned long j = pow(i, 2); j < size; j += i)
            {
                bitset_setbit(pole, j, 1);
            }
        }
    }
}
