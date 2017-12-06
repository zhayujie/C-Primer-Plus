#include <stdio.h>
int max_index(double *ar, int n);
int main(void)
{
    double array[] = {1.5, 3.75, 4.3, 2.6, 2.15, 6.66};

    printf("The index of the maximum number is: %d\n", max_index(array, 6));

    return 0;
}

int max_index(double ar[], int n)
{
    int i, max;

    for (max = 0, i = 1; i < n; i++)
        if (ar[max] < ar[i])
            max = i;

    return max;
}

