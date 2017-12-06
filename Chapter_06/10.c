#include <stdio.h>
int main(void)
{
    int lower, upper;
    int num, sum;
    
    printf("Enter lower and upper integer limits: ");
    scanf("%d%d", &lower, &upper);
    while (lower < upper)
    {
        for (sum=0, num=lower; num <= upper; num++)
            sum = sum + num * num;                //计算平方和
        printf("The sums of the squares from %d to %d is %d\n",
        lower * lower, upper * upper, sum);       //输出结果
    
        printf("Enter next set of limits: ");
        scanf("%d%d", &lower, &upper);            //下一次输入
    }
    printf("Done\n");
    
    return 0;
}

        

