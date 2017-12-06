#include <stdio.h>
#define MASK 01
int check_bit(int num, int bit);
int main(void)
{
    int num, bit;

    printf("Please input a integer:\n");
    scanf("%d", &num);
    printf("Now input the position:\n");
    scanf("%d", &bit);
    printf("The number in your position is: %d.\n",
        check_bit(num, bit));
    
    return 0;
}

int check_bit(int num, int bit)
{
    int i;
    
    for (i = 0; i < bit; i++)
    {
        num >>= 1;
    }
    
    return num & MASK;
}
