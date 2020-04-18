#include <stdio.h>

#include "htab.h"
#include "io.h"

#define BUCKETS 1023
#define WORD_LENGTH 127

int main()
{
    htab_t *htab = htab_init(BUCKETS);
    if (htab == NULL)
    {
        fprintf(stderr, "Error: failed to allocate memory.\n");
        return 1;
    }

    char word[WORD_LENGTH];
    while (get_word(word, WORD_LENGTH, stdin) != EOF)
    {
        htab_iterator_t iterator =  htab_lookup_add(htab, word);
        htab_iterator_set_value(iterator, htab_iterator_get_value(iterator) + 1);
    }

    for (htab_iterator_t iterator = htab_begin(htab); !htab_iterator_equal(iterator, htab_end(htab)); iterator = htab_iterator_next(iterator))
    {
        printf("%s\t%d\n", htab_iterator_get_key(iterator), htab_iterator_get_value(iterator));
    }

    htab_free(htab);

    return 0;
}
