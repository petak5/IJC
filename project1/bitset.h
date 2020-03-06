// bitset.h
// Řešení IJC-DU1, příklad a), 4.3.2020
// Autor: Peter Urgoš, FIT

#include <limits.h>
#include <assert.h>
#include <stdlib.h>

#ifndef BITSET_H
#define BITSET_H

typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;

#define is_units(velikost)\
    1 + velikost / (sizeof(unsigned long) * CHAR_BIT) + (velikost % (sizeof(unsigned long) * CHAR_BIT) == 0 ? 0 : 1)

#define bitset_create(jmeno_pole,velikost)\
    unsigned long jmeno_pole[is_units(velikost)] = { velikost };\
    static_assert(velikost > 0, "Velikost pole musi byt vacsia nez 0")

#define bitset_alloc(jmeno_pole,velikost)\
    bitset_t jmeno_pole = (bitset_t) malloc(is_units(velikost) * sizeof(unsigned long));\
    jmeno_pole[0] = velikost;\
    for (unsigned long i = 1; i < is_units(velikost); i++)\
        jmeno_pole[i] = 0;\
    static_assert(velikost > 0, "Velikost pole musi byt vacsia nez 0")

#define bitset_free(jmeno_pole)\
    free(jmeno_pole)


#ifndef USE_INLINE


    #define bitset_size(jmeno_pole)\
        jmeno_pole[0]

    #define bitset_setbit(jmeno_pole,index,vyraz)\
        ((vyraz) ?\
            (jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] |= 1L << (index % (sizeof(unsigned long) * CHAR_BIT))) :\
            (jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] &= ~(1L << (index % (sizeof(unsigned long) * CHAR_BIT)))))

    #define bitset_getbit(jmeno_pole,index)\
        ((jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] & 1L << (index % (sizeof(unsigned long) * CHAR_BIT))) != 0)


#else // USE_INLINE


    inline unsigned long bitset_size(bitset_t jmeno_pole)
    {
        return jmeno_pole[0];
    }

    inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz)
    {
        (vyraz) ?
            (jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] |= 1L << (index % (sizeof(unsigned long) * CHAR_BIT))) :
            (jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] &= ~(1L << (index % (sizeof(unsigned long) * CHAR_BIT))));
    }

    inline int bitset_getbit(bitset_t jmeno_pole, bitset_index_t index)
    {
        return (jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] &= 1L << (index % (sizeof(unsigned long) * CHAR_BIT))) != 0;
    }


#endif // USE_INLINE

#endif // BITSET_H
