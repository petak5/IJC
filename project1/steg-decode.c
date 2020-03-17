// steg-decode.c
// Řešení IJC-DU1, příklad b), 17.3.2020
// Autor: Peter Urgoš - xurgos00, FIT VUT v Brne

#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		error_exit("Neplatny pocet argumentov. Ocakavam 1, ale dostal som '%d'.\n", argc - 1);
	}

	struct ppm *image = ppm_read(argv[1]);

	if (image == NULL)
	{
		error_exit("Nacitanie obrazku zlyhalo.\n");
	}

	unsigned size = image->xsize * image->ysize * 3;

	bitset_alloc(bs, size);

	Eratosthenes(bs);

	unsigned char message[size];
	for (unsigned i = 0; i < size; i++)
	{
		message[i] = 0;
	}

	unsigned counter = 0;
	for (unsigned i = 23; i < size; i++)
	{
		if (bitset_getbit(bs, i) == 0)
		{
			if ((counter % CHAR_BIT) == 0)
			{
				if (counter != 0)
				{
					if (message[counter / CHAR_BIT - 1] == 0)
					{
						break;
					}
				}
			}

			unsigned char bit = (image->data[i] & 1) != 0;

			if (bit)
			{
				bit <<= (counter % CHAR_BIT);
				message[counter / CHAR_BIT] |= bit;
			}

			counter++;
		}
	}

	bitset_free(bs);

	ppm_free(image);

	if (message[counter / CHAR_BIT - 1] != 0)
	{
		error_exit("Sprava v subore neobsahuje koncovy znak (\\0).\n");
	}

	printf("%s\n", message);

	return 0;
}
