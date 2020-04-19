// tail.c
// Brief: IJC-DU2, part 1)
// Date: 19.4.2020
// Author: Peter Urgoš - xurgos00, FIT VUT Brno

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 1023

void usage();

int main(int argc, char *argv[])
{
    long lines_count = 10;
    char *path = NULL;
    FILE *f = NULL;
    int isFirstWarning = 1;
    int changeMode = 0;     // when number is with `+`

    // Process arguments
    if (argc == 1)
    {
        f = stdin;
    }
    else if (argc == 2)
    {
        path = argv[1];
    }
    else if ((argc == 3) || (argc == 4))
    {
        if (strcmp(argv[1], "-n") != 0)
        {
            fprintf(stderr, "Error: invalid arguments.\n");
            return 1;
        }
        if (argc == 3)
        {
            f = stdin;
        }
        else
        {
            path = argv[3];
        }
        // parse
        char *s = NULL;
        lines_count = strtol(argv[2], &s, 10);
        if (strcmp(s, "") != 0)
        {
            fprintf(stderr, "Error: invalid arguments.\n");
            return 1;
        }
        if (lines_count <= 0)
        {
            fprintf(stderr, "Error: size has to be greater than 0.\n");
            return 1;
        }

        if (argv[2][0] == '+')
        {
            changeMode = 1;
        }
    }
    else
    {
        usage();
        return 1;
    }

    // Open file from path if specified in arguments
    if (f == NULL)
    {
        if ((f = fopen(path, "r")) == NULL)
        {
            fprintf(stderr, "Error: failed to open file '%s'.\n", path);
            return 1;
        }
    }

    // change mode - if number was specified with `+`
    // this mode does not have line length limit
    if (changeMode)
    {
        // get rid of first `lines_count - 1`
        for (int count = 0; count < lines_count - 1; )
        {
            int c = fgetc(f);
            if (c == EOF)
            {
                return 0;
            }
            if (c == '\n')
            {
                count++;
            }
        }

        int c;
        while ((c = fgetc(f)) != EOF)
        {
            putchar(c);
        }

        putchar('\n');

        return 0;
    }

    // Create array for the tail lines
    char **lines = (char **)malloc(lines_count * sizeof(char *));
    if (lines == NULL)
    {
        fprintf(stderr, "Error: failed to allocate memory.\n");
        return 1;
    }
    for (int i = 0; i < lines_count; i++)
    {
        lines[i] = (char *)malloc((LINE_LENGTH + 1) * sizeof(char));
        if (lines[i] == NULL)
        {
            fprintf(stderr, "Error: failed to allocate memory.\n");
            return 1;
        }
    }

    // Read from file
    int row = 0;
    int col = 0;
    int rows_read = 0;
    int cols_read = 0;
    int c;
    while ((c = getc(f)) != EOF)
    {
        if (c != '\n')
        {
            if (cols_read >= (LINE_LENGTH - 1))
            {
                if (isFirstWarning)
                {
                    fprintf(stderr, "Error: line length exceeded limit of %d characters. Ignoring the remaining characters.\n", LINE_LENGTH);
                    isFirstWarning = 0;
                }

                lines[row][col] = 0;

                col--;
            }
            else
            {
                lines[row][col] = c;
            }

            col++;
            cols_read++;
        }
        else
        {
            lines[row][col] = 0;
            row++;
            rows_read++;
            col = 0;
            cols_read = 0;

            if (rows_read >= lines_count)
            {
                if (rows_read == lines_count)
                {
                    row--;
                    continue;
                }
                char *tmp = lines[0];
                for (int x = 0; x < (lines_count - 1); x++)
                {
                    lines[x] = lines[x + 1];
                }
                tmp[0] = 0;
                lines[lines_count - 1] = tmp;

                row--;
            }
        }
    }
    lines[row][col] = 0;

    for (int i = 0; i < ((rows_read < lines_count) ? rows_read : lines_count); i++)
    {
        printf("%s\n", lines[i]);
    }

    // Free allocated memory
    for (int i = 0; i < lines_count; i++)
    {
        free(lines[i]);
    }
    free(lines);

    fclose(f);

    return 0;
}

void usage()
{
    fprintf(stderr, "Usage: tail [-n COUNT] [FILE]\n");
}
