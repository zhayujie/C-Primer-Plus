#include<stdio.h>
double calculate(double n1, double n2);
int main(void)
{
    double num1, num2;
    
    printf("Input two numbers: ");
    while (2 == scanf("%lf%lf", &num1, &num2))   //输入两个浮点数
    {
        printf("%f\n", calculate(num1, num2));   //函数调用
        printf("Input your next pair of numbers: ");
    }
    printf("Bye!\n");
    return 0;
}

double calculate(double n1, double n2)
{
    return ((n1 - n2) / (n1 * n2));     //返回运算结果
}
