#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
int main(int argc, char * argv[])
{
    FILE * fp;
    char words[SIZE];

    if (argc < 3)
    {
        fprintf(stderr, "Wrong number of arguments.\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Could not open %s.", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(words, SIZE, fp) != NULL)
    {
        if (strstr(words, argv[1]) != NULL)
            fputs(words, stdout);
    }

    if (fclose(fp) != 0)
        fprintf(stderr, "Error for closing file.\n");

    return 0;
}



