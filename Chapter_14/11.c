#include <stdio.h>
#include <math.h>
#define PSIZE 4
#define SIZE 100

void transform(double [], double [], int, double(*)(double));
double oppsite_val(double);
double double_val(double);

int main(void)
{
    int i, j;
    double source[SIZE], target[SIZE];
    double(*p[PSIZE])(double) = {sin, sqrt, oppsite_val, double_val};
    
    printf("The source array:\n");
    for (i = 0; i <SIZE; i++)
    {
        source[i] = i;
        printf("%7g ", source[i]);
        if (i % 10 == 9)
            printf("\n");
    }
    printf("\n");
    for (i = 0; i < PSIZE; i++)
    {
        printf("The source array %d:\n", i + 1);
        transform(source, target, SIZE, p[i]);
        for (j = 0; j < SIZE; j++)
        {
            printf("%7.2f ", target[j]);
            if (j % 10 == 9)
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

void transform(double source[], double target[], int size,
    double(*pf)(double num))
{
    int i;

    for (i = 0; i <size; i++)
    {
        target[i] = (*pf)(source[i]);
    }
}


double oppsite_val(double num)
{
    return (-1 * num);
}

double double_val(double num)
{
    return (2 * num);
}
