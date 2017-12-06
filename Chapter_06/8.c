#include<stdio.h>
int main(void)
{
    double n1,n2;
    printf("Input two numbers: ");
    while(2==scanf("%lf%lf",&n1,&n2))
    {
        printf("%f\n",(n1-n2)/n1*n2);
        printf("Input your next pair of numbers: ");
    }
    printf("Bye!\n");
    return 0;
}
