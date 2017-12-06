#include <stdio.h>
#define BASE 1000		//基本工资 100美元/h
#define TIME 40			//超过40h为加班
#define	MUL	1.5			//加班时间算作平时的1.5倍
#define	RATE1 0.15		//前300美元的税率
#define RATE2 0.2		//300-450美元的税率
#define RATE3 0.25		//大于450美元的税率
#define BREAK1 300		//税率的第一个分界点
#define BREAK2 450		//税率的第二个分界点
int main(void)
{
    double hour, tax, gross;
    
    printf("Input your work hours in a week: ");
    scanf("%lf", &hour);
    if (hour <= TIME)
        gross = hour * BASE;
    else
        gross = TIME * BASE + (hour - TIME) * MUL * BASE;
    //计算总收入
    if (gross <= BREAK1)
        tax = gross * RATE1;
    else if (gross <= BREAK2)
        tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
    else
        tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2
            + (gross - BREAK2) * RATE3;
    //计算税金
    printf("Your gross income is $%.2lf\nYour tax is $%.2lf\n"
            "Your net income is $%.2lf\n",
            gross, tax, (gross - tax));
    
    return 0;
}


