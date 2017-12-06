#include<stdio.h>
int main(void)
{
    int num,count;
    printf("Input a integer: ");
    scanf("%d",&num);
    count=0;
    while(count++<11)
    {
        printf("%d ",num);
        num++;
    }
    printf("\n");
    return 0;
}
