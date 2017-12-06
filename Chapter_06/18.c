#include <stdio.h>
#define	INITIAL_NUMBER 5   //初始朋友数为5人
#define DUNBAR_NUMBER 150  //邓巴数
int main(void)
{
    int week;
    int number = INITIAL_NUMBER;

    for (week = 1; number <= DUNBAR_NUMBER; week++)
    {
        number = (number - week) * 2;		//计算每周的朋友数量
        printf("After %d week, the number of Rabnud's friends is %d\n", week, number);
    }

    return 0;
}
    

    
