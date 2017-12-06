#include <stdio.h>
#define SIZE 40
char * gets_n(char ar[], int n);
int main(void)
{
    char str[SIZE];

    gets_n(str, 10);
    puts(str);

    return 0;
}

char * gets_n(char ar[], int n)
{
    int count = 0;

    while (count < n)
        ar[count++] = getchar();
    ar[count] = '\0';

    return ar;
}
