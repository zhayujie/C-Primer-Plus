#include <stdio.h>
void sort(double * x, double * y, double * z);
int main(void)
{
    double num1, num2 ,num3;

    printf("Enter 3 numbers: ");
    scanf("%lf%lf%lf", &num1, &num2, &num3);
    printf("Originally\nnum1 = %.2f, num2 = %.2f, num3 = %.2f\n",
            num1, num2, num3);
    sort(&num1, &num2, &num3);
    printf("Now\nnum1 = %.2f, num2 = %.2f, num3 = %.2f\n",
            num1, num2, num3);

    return 0;
}

void sort(double * x, double * y, double * z)
{
    double temp;
    if (*y < *x)
    {
        temp = *y;
        *y = *x;
        *x = temp;
    }
    if (*z < *x)
    {
        temp = *z;
        *z = *x;
        *x = temp;
    }
    if (*z < *y)
    {
        temp = *z;
        *z = *y;
        *y = temp;
    }
}

        
