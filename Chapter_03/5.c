#include<stdio.h>
int main(void)
{
    int age;
    double seconds;
    
    printf("please input your age: ");
    scanf("%d",&age);
    seconds=age*3.156e7;
    printf("the corresponding seconds are: %e\n",seconds);

    return 0;
}
