#include <stdio.h>
#define SIZE 8
int main(void)
{
    int num[SIZE];
    int index;
    
    printf("Enter 8 integers: ");
    for (index=0; index<SIZE; index++)        //输入8个整数
        scanf("%d", &num[index]);
    for (index=SIZE-1; index >= 0; index--)	  //倒序输出
        printf("%d ", num[index]);
    printf("\n");

    return 0;
}


