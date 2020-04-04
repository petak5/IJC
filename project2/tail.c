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

    // Create array for the tail lines
    char *lines = (char *)malloc(lines_count * sizeof(char) * (LINE_LENGTH + 1));
    if (lines == NULL)
    {
        fprintf(stderr, "Error: failed to allocate memory.\n");
        return 1;
    }


    free(lines);

    fclose(f);

    return 0;
}

void usage()
{
    fprintf(stderr, "Usage: tail [-n COUNT] [FILE]\n");
}
