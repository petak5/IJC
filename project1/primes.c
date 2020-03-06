#include <stdio.h>
#include "bitset.h"
#include "eratosthenes.h"

int main(void)
{
    bitset_create(x, 50000000);
    
    Eratosthenes(x);
    printf("%lu\n", x[1]);

    int counter = 0;
    for (unsigned long i = 49999999; i > 1; i--)
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


    return 0;
}
