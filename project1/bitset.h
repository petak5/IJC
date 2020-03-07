// bitset.h
// Řešení IJC-DU1, příklad a), 4.3.2020
// Autor: Peter Urgoš, FIT

#include <limits.h>
#include <assert.h>
#include <stdlib.h>
#include "error.h"

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
		jmeno_pole[0] = velikost

#define bitset_free(jmeno_pole)\
	free(jmeno_pole)

#ifndef USE_INLINE


    #define bitset_size(jmeno_pole)\
        jmeno_pole[0]

    #define bitset_setbit(jmeno_pole,index,vyraz)\
		(((index + 1) > bitset_size(jmeno_pole))\
			? (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1), 0)\
	        : ((vyraz)\
    	        ? (jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] |= 1L << (index % (sizeof(unsigned long) * CHAR_BIT)))\
        	    : (jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] &= ~(1L << (index % (sizeof(unsigned long) * CHAR_BIT))))))

    #define bitset_getbit(jmeno_pole,index)\
		(((index + 1) > bitset_size(jmeno_pole))\
			? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1), 0)\
        	: ((jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] & 1L << (index % (sizeof(unsigned long) * CHAR_BIT))) != 0))


#else // USE_INLINE


    extern inline unsigned long bitset_size(bitset_t jmeno_pole)
    {
        return jmeno_pole[0];
    }

    extern inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz)
    {
		if ((index + 1) > bitset_size(jmeno_pole))
		{
			error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1);
		}
		else
		{
        	(vyraz)
            	? (jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] |= 1L << (index % (sizeof(unsigned long) * CHAR_BIT)))
            	: (jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] &= ~(1L << (index % (sizeof(unsigned long) * CHAR_BIT))));
		}
    }

    extern inline int bitset_getbit(bitset_t jmeno_pole, bitset_index_t index)
    {
		if ((index + 1) > bitset_size(jmeno_pole))
		{
			error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1);
			return 1;
		}
		else
		{
        	return (jmeno_pole[1 + index / (sizeof(unsigned long) * CHAR_BIT)] &= 1L << (index % (sizeof(unsigned long) * CHAR_BIT))) != 0;
		}
    }


#endif // USE_INLINE

#endif // BITSET_H
