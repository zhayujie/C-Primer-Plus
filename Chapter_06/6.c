#include<stdio.h>
int main(void)
{

    int max,min,num;

    printf("Input the min and max: ");
    scanf("%d%d",&min,&max);
    printf("%10s%10s%10s\n","number","square","cube");
    for(num=min;num<=max;num++)
        printf("%10d%10d%10d\n",num,num*num,num*num*num);
    return 0;
}
