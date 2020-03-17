// bitset.h
// Řešení IJC-DU1, příklad a), 17.3.2020
// Autor: Peter Urgoš - xurgos00, FIT VUT v Brne

#ifndef BITSET_H
#define BITSET_H

#include <limits.h>
#include <assert.h>
#include <stdlib.h>
#include "error.h"

typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;

// pocet bitov v type unsigned long
#define SIZE (sizeof(unsigned long) * CHAR_BIT)

// makro pre vypocet velkosti pola typu unsigned long pre `velikost` bitov + 1 polozka pre ulozenie velkosti
#define _is_units(velikost)\
    (1 + velikost / SIZE + (velikost % SIZE == 0 ? 0 : 1))

// "privatne" makro pre nastavenie bitu
#define _setbit(jmeno_pole, index, vyraz)\
	((vyraz)\
    	? (jmeno_pole[1 + index / SIZE] |= 1L << (index % SIZE))\
    	: (jmeno_pole[1 + index / SIZE] &= ~(1L << (index % SIZE))))

// "privatne" makro pre citanie bitu
#define _getbit(jmeno_pole, index)\
	((jmeno_pole[1 + index / SIZE] & 1L << (index % SIZE)) != 0)


// vytvori staticke pole s menom `jmeno_pole` o velkosti potrebnej pre uschovanie `velikost` bitov + 1 polozka pre ulozenie tejto velkosti
#define bitset_create(jmeno_pole, velikost)\
    unsigned long jmeno_pole[_is_units(velikost)] = { velikost };\
    static_assert(velikost > 0, "Velikost pole musi byt vacsia nez 0")

// vytvori premennu `jmeno_pole` a dynamicky alokuje pamat pre pole velkosti potrebnej pre uschovanie `velikost` bitov + 1 polozka pre ulozenie tejto velkosti
#define bitset_alloc(jmeno_pole, velikost)\
	bitset_t jmeno_pole = (bitset_t) malloc(_is_units(velikost) * sizeof(unsigned long));\
	do {\
		assert((jmeno_pole != NULL) && "bitset_alloc: Chyba alokace paměti");\
		jmeno_pole[0] = velikost;\
		for (unsigned i = 1; i < _is_units(velikost); i++)\
		{\
			jmeno_pole[i] = 0;\
		}\
	} while (0)

// uvolni pamat dinamicky alokovaneho pola s menom `jmeno_pole`
#define bitset_free(jmeno_pole)\
	free(jmeno_pole)

// MAKRO verzia
#ifndef USE_INLINE

// makro - vrati pocet bitov ulozenich v `jmeno_pole`
#define bitset_size(jmeno_pole)\
    jmeno_pole[0]

// makro - nastavi bit v `jmeno_pole` na indexe `index` na 0 alebo 1 podla vysledku `vyraz`u
#define bitset_setbit(jmeno_pole,index,vyraz)\
	((index >= bitset_size(jmeno_pole)))\
		? (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1), 0)\
	    : (_setbit(jmeno_pole, index, vyraz)))

// makro pre vypocet hodnoty bitu v `jmeno_pole` na indexe `index`
#define bitset_getbit(jmeno_pole,index)\
	((index >= bitset_size(jmeno_pole)))\
		? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1), 0)\
    	: (_getbit(jmeno_pole, index)))


// INLINE verzia
#else // USE_INLINE

	// vrati pocet bitov ulozenich v `jmeno_pole`
    extern inline unsigned long bitset_size(bitset_t jmeno_pole)
    {
        return jmeno_pole[0];
    }

	// inline funkcia - nastavi bit v `jmeno_pole` na indexe `index` na 0 alebo 1 podla vysledku `vyraz`u
    extern inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz)
    {
		if (index >= bitset_size(jmeno_pole))
		{
			error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1);
		}
		else
		{
        	_setbit(jmeno_pole, index, vyraz);
		}
    }

	// inline funkcia vrati hodnotu bitu v `jmeno_pole` na indexe `index`
    extern inline int bitset_getbit(bitset_t jmeno_pole, bitset_index_t index)
    {
		if (index >= bitset_size(jmeno_pole)))
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
