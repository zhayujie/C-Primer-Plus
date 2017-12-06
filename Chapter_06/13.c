#include <stdio.h>
#define SIZE 8
int main(void)
{
    int index, count, num[SIZE];
     
    for (index = 0, count = 1; index < SIZE; index++)
    {
        count *= 2;
        num[index] = count;
    }											//for循环将数组元素设为2的前8次幂
    
    index=0;									//初始化index的值
    do
    printf("%d ", num[index++]);
    while (index < SIZE);						//do while循环显示数组元素的值
    printf("\n");

    return 0;
}
