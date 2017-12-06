#include <stdio.h>
#define RATE_DAPHNE 0.1
#define RATE_DEIRDRE 0.05					//两人的利率
#define	MONEY 100
int main(void)
{
    int year;
    double daphne = MONEY, deirdre = MONEY;	//两人的初始投资额相同

    for (year = 1; daphne >= deirdre; year++)
    {
        daphne += MONEY * RATE_DAPHNE;
        deirdre += deirdre * RATE_DEIRDRE;
    }
    //计算Deirdre投资额超过Daphne需要的年数和当时的金额
    printf("After %d year, Deirdre's investment will be more than Daphne's,\n"
        "Daphne's investment will be $%lf,\nand Deirdre's investment will be $%lf.\n",
        year, daphne, deirdre);				//输出结果

    return 0;
}
    
