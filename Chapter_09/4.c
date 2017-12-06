#include <stdio.h>
double har_mean(double num1, double num2);
int main(void)
{
    double num1, num2;
    printf("Enter two numbers: ");
    scanf("%lf%lf", &num1, &num2);
    printf("The harmonic mean is: %f\n", har_mean(num1, num2));
}

double har_mean(double num1, double num2)
{
    return 1 / (1 / num1 + 1 / num2);
}
