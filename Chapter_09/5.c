#include <stdio.h>
void larger_of(double * x, double * y);
int main(void)
{
    double num1, num2;

    printf("Input two numbers: ");
    scanf("%lf%lf", &num1, &num2);
    printf("Originally, num1 = %f, num2 = %f\n",
            num1, num2);
    larger_of(&num1, &num2);
    printf("Now, num1 = %f, num2 = %f\n", num1, num2);

    return 0;
}

void larger_of(double * x, double * y)
{
    *x > *y ? (*y = *x) : (*x = *y);
}


