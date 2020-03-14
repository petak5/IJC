#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		error_exit("Invalid arguments. Expecting 2 arguments but were given: %d\n", argc);
	}

	struct ppm *image = ppm_read(argv[1]);

	if (image == NULL)
	{
		error_exit("Failed to open image.\n");
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
	for (unsigned i = 23; i < (size); i++)
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
		error_exit("Message has no ending \\0 char.\n");
	}

	printf("%s\n", message);

	return 0;
}
