#include <stdio.h>
#define RATE1 0.15
#define RATE2 0.28
#define SINGLE 17850	//单身人群的税率分界点
#define HOST 23900		//户主人群的税率分界点
#define MAR_SHA	29750	//已婚共有人群的分界点
#define MAR_DEV	14875	//已婚离异人群的分界点
int main(void)
{
    int num;
    double income, tax_break, tax;

    printpart: printf("Please enter Corresponding"
                    "figures to select the type\n");
    printf("1 single, 2 host, 3 married and shared, "
            "4 married but devoced and 5 to quit.\n");
    scanf("%d", &num);
    switch (num)
    {
        case 1: tax_break = SINGLE;
                break;
        case 2: tax_break = HOST;
                break;
        case 3: tax_break = MAR_SHA;
                break;
        case 4: tax_break = MAR_DEV;
                break;
        case 5:	printf("quit.\n");
                return 0;
        default: printf("Please input right number.");
                 goto printpart;		//回到输入阶段
    }
    printf("Enter your income: ");		//指定种类和收入
    while (scanf("%lf", &income) == 1)
    {
        if (income <= tax_break)
            tax = income * RATE1;
        else
            tax = tax_break * RATE1 + (income - tax_break) * RATE2;
        //计算税金
        printf("The tax is $%.2lf.\n", tax);
        printf("Your next input: \n");
        goto printpart;					//回到输入阶段
    }

    return 0;
}
    



    
    
