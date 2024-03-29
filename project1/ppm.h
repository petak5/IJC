// ppm.h
// Řešení IJC-DU1, příklad b), 17.3.2020
// Autor: Peter Urgoš - xurgos00, FIT VUT v Brne

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

#define MAX_LIMIT (8000 * 8000)

struct ppm {
	unsigned xsize;
	unsigned ysize;
	char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);
