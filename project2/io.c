#include "io.h"

int get_word(char *s, int max, FILE *f)
{
    if (max <= 0)
    {
        return EOF;
    }

    int c = 0;
    int count = 0;
    int is_reading_word = 0;
    static int first_warning = 1;

    while((c = fgetc(f)) != EOF)
    {
        if (count >= max - 1)
        {
            s[count] = '\0';

            if (first_warning)
            {
                fprintf(stderr, "Warning: max string length exceeded, skipping the rest of the word.\n");
                first_warning = 0;
            }

            if (isspace(c))
            {
                break;
            }
            else
            {
                continue;
            }
        }

        if (is_reading_word)
        {
            if (isspace(c))
            {
                break;
            }

            s[count] = c;
            count++;
        }
        else
        {
            if (!isspace(c))
            {
                s[count] = c;
                count++;
                is_reading_word = 1;
            }
        }
    }

    if (count == 0)
    {
        return EOF;
    }

    s[count] = '\0';

    return count;
}
