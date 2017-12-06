#include <stdio.h>
#include <ctype.h>
#define SIZE 80
char * gets_n(char *ar, int n);
int main(void)
{
    char str[SIZE];
    
    printf("Enter some characters:\n");
    gets_n(str, 10);
    puts(str);

    return 0;
}

char * gets_n(char *ar, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        *(ar + i) = getchar();
        if (isspace(*(ar + i)))
            break;
    }
    *(ar + i) = '\0';

    return ar;
}
