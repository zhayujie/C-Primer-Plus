#include <stdio.h>
#define INITIAL_MONEY 100			//账户初始金额为100万元
#define ANNUAL_RATE 0.08			//年利率为8%
int main(void)
{
    int year;
    double money;
    
    for(year = 1, money=INITIAL_MONEY; money>0; year++)
        money += money * ANNUAL_RATE - 10;			//计算每年年终的账户余额
    printf("After %d years, Chuckie will draw all money from his account.\n", year);

    return 0;
}
