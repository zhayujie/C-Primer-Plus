#include <stdio.h>
#define BASE1 8.75
#define BASE2 9.33
#define BASE3 10.00
#define BASE4 11.20
//四种等级的基本工资
#define TIME 40			//超过40h为加班
#define	MUL	1.5		//加班时间算作平时的1.5倍
#define	RATE1 0.15		//前300美元的税率
#define RATE2 0.2			//300-450美元的税率
#define RATE3 0.25		//大于450美元的税率
#define BREAK1 300		//税率的第一个分界点
#define BREAK2 450		//税率的第二个分界点
#define LENGTH 65		//*的长度

char get_choice(void);
void calculate(double base);
int main(void)
{
    double base;
    char choice;
    
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a': base = BASE1;
                      break;
            case 'b': base = BASE2;
                      break;
            case 'c': base = BASE3;
                      break;
            case 'd': base = BASE4;
                      break;
            default: printf("Please respond with a, b, c, d or q.\n");
                     break;
        }
        if (choice >= 'a' && choice <= 'd')
            calculate(base);
    }

    return 0;
}
    
//计算和输出结果的函数
void calculate(double base)
{
    double hour, gross, tax;

    printf("Input your work hours in a week: ");
    scanf("%lf", &hour);
    while (getchar() != '\n')
        continue;					//跳过回车
    if (hour <= TIME)
        gross = hour * base;
    else
        gross = TIME * base + (hour - TIME) * MUL * base;
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
    printf("\n");
}

//打印选择界面并让用户输入的函数
char get_choice(void)
{
    char ch;
    int count;

    for (count = 0; count < LENGTH; count++)
        printf("*");
    printf("\nEnter the letter corresponding to the desired pay rate or action:\n");
    printf("%-36s%s","a) $8.75/hr", "b) $9.33/hr\n");
    printf("%-36s%s","c) $10.00/hr", "d) $11.20/hr\n");
    printf("%s\n", "q) quit");
    for (count = 0; count < LENGTH; count++)
        printf("*");
    printf("\n");

    ch = getchar();
    while (getchar() != '\n')
        continue;					//跳过输出行剩余内容

    return ch;
}
