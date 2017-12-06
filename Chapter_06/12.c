#include <stdio.h>
int main(void)
{
    double sum1=0, sum2=0;
    int count, items, sign;
    
    printf("Enter the items: ");
    scanf("%d", &items);                                           //输入序列的项数
    for (count=1, sign=1; count <= items; count++, sign *= -1)
    {
        sum1 += 1.0 / count;
        sum2 += 1.0 * sign / count;
    }															   //分别计算两序列的和
    printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... = %f\n", sum1);
    printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... = %f\n", sum2);


    return 0;
}
