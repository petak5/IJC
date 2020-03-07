#include "ppm.h"

struct ppm * ppm_read(const char * filename)
{
	FILE *f = fopen(filename, "r");
	if (f == NULL)
	{
		warning_msg("Failed to open file %s\n", filename);
		return NULL;
	}

	unsigned x, y;
	fscanf(f, "P6 %u %u 255 ", &x, &y);

	if ((x == 0) || (y == 0))
	{
		fclose(f);
		warning_msg("Invalid dimensions. Can not be 0\n");
		return NULL;
	}

	if ((x * y) > MAX_LIMIT)
	{
		fclose(f);
		warning_msg("Image dimensions of '%dx%d' are out of the limit of %d", x, y, MAX_LIMIT);
		return NULL;
	}

	struct ppm *image = malloc(sizeof(struct ppm) + 3 * x * y * sizeof(char));
	
	if (image == NULL)
	{
		fclose(f);
		warning_msg("Failed to allocate memory for the image.\n");
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
			warning_msg("The file contains more data than declared in the header.\n");
			return NULL;
		}

		image->data[counter] = c;

		counter++;
	}

	if ((unsigned)counter < (x * y * 3))
	{
		ppm_free(image);
		fclose(f);
		warning_msg("File too small. EOF ocured before '%d' bytes were read.\n", x * y * 3);
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
