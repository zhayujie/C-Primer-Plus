#include <stdio.h>
int main(void)
{
    int div, prime;
    int num, count;
    int flag;

    printf("Input a positive integer: ");
    scanf("%d", &num);
    printf("The prime numbers in range:\n");
    for (prime = 2; prime <= num; prime++)	//外层循环显示所有素数
    {
        flag = 1;
        for (div = 2; (div * div) <= prime; div++)
        {
            if (prime % div == 0)
                flag = 0;
        }									//内层循环检验是否为素数
        if (flag)							//利用标记flag判断
            printf("%d ",prime);
    }
    printf("\n");
    
    return 0;
}



