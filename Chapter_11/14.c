#include <stdio.h>
#include <stdlib.h>
double mypower(double n, int exp);
int main(int argc, char * argv[])
{
    printf("The result is: %g",
            mypower(atof(argv[1]), atoi(argv[2])));
}


double mypower(double n, int exp)
{
    double pow;

    if (exp > 0)
        for (pow = 1; exp > 0; exp--)
            pow *= n;
    else if (exp < 0)
    {	if (!n)
            printf("It's not defined!\n");
        for (pow = 1; exp < 0; exp++)
            pow *= (1 / n);
    }
    else if (n)
        pow = 1;
    else
    {	pow = 1 / n;
        printf("It's not defined!\n");
    }

    return pow;
}
