#include<stdio.h>
int main(void)
{
    int count,sum,days;
    printf("Input the number of days: ");
    scanf("%d",&days);
    count=sum=0;
    while(count++<days)
        sum=sum+count*count;
    printf("The money you earned: %d\n",sum);
    return 0;
}








