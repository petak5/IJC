#include <stdio.h>
#include <time.h>
#include "bitset.h"
#include "eratosthenes.h"

int main(void)
{
	clock_t start = clock();

    bitset_create(x, 500000000);
    
    Eratosthenes(x);

    int counter = 0;
    for (unsigned long i = 499999999; i > 1; i--)
    {
        if (bitset_getbit(x, i) == 0)
        {
            counter++;
            printf("%lu\n", i);

            if (counter >= 10)
            {
                break;
            }
        }
    }

	fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

    return 0;
}
