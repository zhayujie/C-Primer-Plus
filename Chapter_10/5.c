#include <stdio.h>
double gap(double ar[], int n);
int main(void)
{
    double array[] = {1.5, 3.75, 4.3, 2.6, 2.15, 6.66};

    printf("The difference between the maximum and minimum "
           "values is:\n%g\n", gap(array, 6));
    
    return 0;
}

double gap(double ar[], int n)
{
    int i;
    double max, min;

    max = min = ar[0];
    for (i = 0; i < n; i++)
    {
        if (max < ar[i])
            max = ar[i];
        if (min > ar[i])
            min = ar[i];
    }

    return (max - min);
}
