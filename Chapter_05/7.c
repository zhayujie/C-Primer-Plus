#include<stdio.h>
void cube(double n);
int main(void)
{
    double num;
    printf("Input a number: ");
    scanf("%lf",&num);
    cube(num);
}

void cube(double n)
{
    printf("The cube of %f is %f\n",n,n*n*n);
}






