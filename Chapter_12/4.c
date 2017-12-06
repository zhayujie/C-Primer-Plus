#include <stdio.h>
#define TIMES 20
void called_count(void);
static int count;
int main(void)
{
    int i;

    for (i = 0; i < TIMES; i++)
        called_count();
    printf("The times is %d.\n", count);
}

void called_count(void)
{
    count++;
}
