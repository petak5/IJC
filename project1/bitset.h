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

#define SIZE (sizeof(unsigned long) * CHAR_BIT)

#define _is_units(velikost)\
    1 + velikost / SIZE + (velikost % SIZE == 0 ? 0 : 1)

#define _setbit(jmeno_pole, index, vyraz)\
	((vyraz)\
    	? (jmeno_pole[1 + index / SIZE] |= 1L << (index % SIZE))\
    	: (jmeno_pole[1 + index / SIZE] &= ~(1L << (index % SIZE))))

#define _getbit(jmeno_pole, index)\
	((jmeno_pole[1 + index / SIZE] & 1L << (index % SIZE)) != 0)



#define bitset_create(jmeno_pole,velikost)\
    unsigned long jmeno_pole[_is_units(velikost)] = { velikost };\
    static_assert(velikost > 0, "Velikost pole musi byt vacsia nez 0")

#define bitset_alloc(jmeno_pole,velikost)\
	bitset_t jmeno_pole = (bitset_t) malloc(_is_units(velikost) * sizeof(unsigned long));\
	do {\
		assert((jmeno_pole != NULL) && "bitset_alloc: Chyba alokace paměti");\
		jmeno_pole[0] = velikost;\
	} while (0)

#define bitset_free(jmeno_pole)\
	free(jmeno_pole)

#ifndef USE_INLINE


#define bitset_size(jmeno_pole)\
    jmeno_pole[0]

#define bitset_setbit(jmeno_pole,index,vyraz)\
	(((index + 1) > bitset_size(jmeno_pole))\
		? (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1), 0)\
	    : (_setbit(jmeno_pole, index, vyraz)))

#define bitset_getbit(jmeno_pole,index)\
	(((index + 1) > bitset_size(jmeno_pole))\
		? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1), 0)\
    	: (_getbit(jmeno_pole, index)))


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
        	_setbit(jmeno_pole, index, vyraz);
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
        	return _getbit(jmeno_pole, index);
		}
    }


#endif // USE_INLINE

#endif // BITSET_H
