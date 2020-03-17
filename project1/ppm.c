// ppm.c
// Řešení IJC-DU1, příklad b), 17.3.2020
// Autor: Peter Urgoš - xurgos00, FIT VUT v Brne

#include "ppm.h"

struct ppm * ppm_read(const char * filename)
{
	FILE *f = fopen(filename, "r");
	if (f == NULL)
	{
		warning_msg("Zlyhalo otvorenie suboru '%s'.\n", filename);
		return NULL;
	}

	unsigned x, y;
	if ((fscanf(f, "P6 %u %u 255 ", &x, &y)) != 2)
	{
		fclose(f);
		warning_msg("Neplatny format hlavicky suboru '%s'.\n", filename);
		return NULL;
	}

	if ((x <= 0) || (y <= 0))
	{
		fclose(f);
		warning_msg("Neplatne rozmery, musia byt vacsie nez 0.\n");
		return NULL;
	}

	if ((x * y) > MAX_LIMIT)
	{
		fclose(f);
		warning_msg("Rozmery obrazku '%dx%d' su vacsie nez limit s hodnotou %d.\n", x, y, MAX_LIMIT);
		return NULL;
	}

	struct ppm *image = malloc(sizeof(struct ppm) + 3 * x * y * sizeof(char));
	
	if (image == NULL)
	{
		fclose(f);
		warning_msg("Alokacia pamate zlyhala.\n");
		return NULL;
	}

	image->xsize = x;
	image->ysize = y;

	int counter = 0;
	int c = 0;
	while((c = fgetc(f)) != EOF)
	{
		if ((unsigned)counter >= (x * y * 3))
		{
			ppm_free(image);
			fclose(f);
			warning_msg("Subor obsahuje viacej dat nez je deklarovanych v hlavicke.\n");
			return NULL;
		}

		image->data[counter] = c;

		counter++;
	}

	if ((unsigned)counter < (x * y * 3))
	{
		ppm_free(image);
		fclose(f);
		warning_msg("Subor obsahuje menej dat nez je deklarovanych v hlavicke.\n");
		return NULL;
	}

	fclose(f);

	return image;
}

void ppm_free(struct ppm *p)
{
	if (p != NULL)
	{
		free(p);
	}
}
