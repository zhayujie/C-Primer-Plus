#include<stdio.h>
#define DAYS_PER_WEEK 7 //一周7天
int main(void)
{
    int day,week,left;
    printf("Input the number of days: ");
    scanf("%d",&day);
    while(day>0)
    {
        week=day/DAYS_PER_WEEK;
        left=day%DAYS_PER_WEEK;
        printf("%d days are %d weeks, %d days.\n",day,week,left);
        printf("Next input: ");
        scanf("%d",&day);
    }
        return 0;
}
