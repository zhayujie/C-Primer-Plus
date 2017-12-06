#include <stdio.h>
int main(void)
{
    int ch;
    int count = 0;

    while ((ch = getchar()) != EOF)
        count++;
    printf("The number of characters is %d\n", count);

    return 0;
}
