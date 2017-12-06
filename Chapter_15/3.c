#include <stdio.h>
#include <limits.h>
#define MASK 01

int count_bit_on(int num);

int main(void)
{
    int num;

    printf("Please input a integer:\n");
    scanf("%d", &num);
    printf("The number of bit on is: %d\n",
        count_bit_on(num));

    return 0;
}

int count_bit_on(int num)
{
    int i;
    int count = 0;
    int size = CHAR_BIT * sizeof(int);
    
    for (i = 0; i < size; i++)
    {
        if (num & MASK)
        {
            count++;
        }
        num >>= 1;
    }

    return count;
}
