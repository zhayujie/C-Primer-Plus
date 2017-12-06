#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
    int i;
    char ch;
    FILE * fp;
    int count = 0;
    
    if (argc < 2)
    {
        fprintf(stderr, "the wrong number of arguments.");
        exit(EXIT_FAILURE);
    }

    if (argc == 2)
    {
        printf("Input some texts:\n");
        while ((ch = getchar()) != EOF)
        {
            if (ch == argv[1][0])
                count++;
        }
        printf("the \"%s\" in your input: %d times.",
            argv[1], count);
    }
    
    else
    {
        for (i = 2; i < argc; i++)
        {
            count = 0;
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Could not open the %s.", argv[i]);
                continue;
            }
            while ((ch = getc(fp)) != EOF)
            {
                if (ch == argv[1][0])
                    count++;
            }
            fprintf(stdout, "the \"%s\" in %s: %d times.\n",
                argv[1], argv[i], count);
        }
    }

    return 0;
}
