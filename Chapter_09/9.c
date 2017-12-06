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
    double pow;

    if (p > 0)
        pow = n * power(n, p - 1);
    else if (p < 0)
        if (n != 0)
            pow = (1.0 / n) * power(n, p + 1);
        else
            pow = 0;
    else
        pow = 1;

    return pow;
}
