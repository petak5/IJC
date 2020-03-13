#include <stdio.h>
#include <time.h>
#include "bitset.h"
#include "eratosthenes.h"

int main(void)
{
	clock_t start = clock();

	bitset_create(x, 500000001);

    Eratosthenes(x);

    int counter = 0;
	unsigned long results[10];
    for (unsigned long i = bitset_size(x) - 1; i > 1; i--)
    {
        if (bitset_getbit(x, i) == 0)
        {
			results[counter] = i;
            counter++;

            if (counter >= 10)
            {
                break;
            }
        }
    }

	for (int i = counter - 1; i >= 0; i--)
	{
		printf("%lu\n", results[i]);
	}

	fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

    return 0;
}
