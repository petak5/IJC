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

	bitset_alloc(bs, image->xsize * image->ysize * 3);

	Eratosthenes(bs);
	
	bitset_free(bs);

	ppm_free(image);

	return 0;
}
