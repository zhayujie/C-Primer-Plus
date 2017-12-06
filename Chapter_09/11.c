#include <stdio.h>
unsigned long Fibonacci(unsigned n);
int main(void)
{
    unsigned int num;
    int count;

    printf("Input the number of the items (q to quit): ");
    while (scanf("%u", &num) == 1)
    {
        for (count = 1; count <= num; count++)
            printf("%lu ", Fibonacci(count));
        printf("\nYour next input(q to quit): ");
    }
    printf("Bye.\n");

    return 0;
}

unsigned long Fibonacci(unsigned n)
{
    int count, temp;
    int n1 = 1, n2 = 1;

    if (n > 2)
        for (count = 3; count <= n; count++)
        {
            temp = n1 + n2;
            n1 = n2;
            n2 = temp;
        }
    else
        n2 = 1;

    return n2;
}
        
