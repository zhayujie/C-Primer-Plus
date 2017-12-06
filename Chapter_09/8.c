#include <stdio.h>
double power(double n, int p);
int main(void)
{
    double x, xpow;
    int exp;

    printf("Enter a number and the interger power (q to quit):\n");
    while (scanf("%lf%d", &x, &exp) == 2)
    {
        xpow = power(x, exp);
        printf("%.3g to the power %d is %g\n", x, exp, xpow);
        printf("Enter the next pair of numbers or q to quit.\n");
    }
    printf("Bye.\n");
}

double power(double n, int p)
{
    int count;
    double pow = 1;
    
    if (p == 0)
        if (n == 0)
        {
            pow = 1;
            printf("It is not defined, so the value is treated as 1\n");
        }
        else
            pow = 1;
    
    else if (p > 0)
        for (count = 0; count < p; count++)
            pow *= n;
    
    else
        if (n != 0)
            for (count = 0; count > p; count--)
                pow /= n;
        else
            pow = 0;

        return pow;
}
