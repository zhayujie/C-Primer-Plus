#include<stdio.h>
int main(void)
{
    int num1,num2;
    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d",&num1);
    printf("Now enter the first operand: ");
    scanf("%d",&num2);
    while(num2>0)
    {
        printf("%d %% %d is %d\n",num2,num1,num2%num1);
        printf("Enter next number for first operand (<= 0 to quit): ");
        scanf("%d",&num2);
    }
        printf("Done\n");
}








