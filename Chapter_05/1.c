#include<stdio.h>
#define H_P_M 60  //1h=60min
int main(void)
{
    int hour,min,left;
    printf("Enter the number of minutes: ");
    scanf("%d",&min);
    while(min>0)
    {
        hour=min/H_P_M;
        left=min%H_P_M;
        printf("%d minutes is %d hours and %d minutes.\n",min,hour,left);
        printf("Enter your next value: ");
        scanf("%d",&min);
    }
    printf("Good bye!\n");
    return 0;
}
