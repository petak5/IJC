#include "ppm.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		error_exit("Invalid arguments. Expecting 2 arguments but were given: %d\n", argc);
	}

	struct ppm *image = ppm_read(argv[1]);

	if (image == NULL)
	{
		printf("That's really sad :(\n");
		return 1;
	}

	printf("The image dimensions are: %ux%u\n", image->xsize, image->ysize);

	return 0;
}
