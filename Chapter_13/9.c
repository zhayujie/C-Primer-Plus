#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41
int main(void)
{
    FILE * fp;
    char words[MAX];
    char name[MAX];
    int count = 0;

    printf("Please input the file name:\n");
    gets(name);
    if ((fp = fopen(name, "a+")) == NULL)
    {
        fprintf(stderr, "can't open \"%s\" file.\n", name);
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%s\n", words);
    puts("File contents:");
    rewind(fp);
    while (fscanf(fp, "%s", words) != EOF)
    {
        count++;
        fprintf(stdout, "%d. %s\n", count, words);
    }
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}
