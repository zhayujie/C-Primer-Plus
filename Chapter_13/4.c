#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
    char ch;
    int i;
    FILE * fp;

    for (i = 1; i < argc; i++)
    {
        printf("File %d:\n", i);
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Could not open %s.\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        while ((ch = getc(fp)) != EOF)
            putchar(ch);
        printf("\n");
    }

    return 0;
}
