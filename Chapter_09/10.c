#include <stdio.h>
void to_base_n(unsigned long n, unsigned int base);
int main(void)
{
    unsigned long num;
    unsigned int base;

    printf("Enter an integer and the base from 2 to 10 (q to quit): ");
    while (scanf("%lu%u", &num, &base) == 2)
    {
        printf("Equivalent number on the base of %u: ", base);
        to_base_n(num, base);
        printf("\nEnter your next pair of numbers(q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

void to_base_n(unsigned long n, unsigned int base)
{
    int r;

    r = n % base;
    if (n >= base)
        to_base_n(n / base, base);
    printf("%d", r);
}




