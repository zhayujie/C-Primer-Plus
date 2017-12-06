#include <stdio.h>
#include <ctype.h>
#define ARTICHOKE 2.05		//洋蓟2.05美元/磅
#define BEET 1.15			//甜菜1.15美元/磅
#define CARROT 1.09			//胡萝卜1.09美元/磅
#define	DISCOUNT_LIMIT 100
//包装费和运费打折要求订单100美元
#define DISCOUNT_RATE 0.05	//折扣为%5
#define BREAK1 5
#define BREAK2 20			//装运费的分界点
#define	FEE1 6.5
#define	FEE2 14
#define FEE3_RATE 0.5
//不同重量区间的装运费，其中超过20磅的每续重一磅
//增加0.5元
int main(void)
{
    double weight;
    double weight_artichoke = 0;
    double weight_beet = 0;
    double weight_carrot = 0;	//购买三种蔬菜的重量
    double total_weight;	//总重量
    double veg_cost;		//三种蔬菜总共花费
    double order_cost;		//订单总额
    double total_cost;		//费用总额
    double pack_tran_fee;	//装运费
    double discount;
    int count = 0;
    char ch;

    printf("Please select the vegetables you want to buy:\n");
    printf("a: artichoke  $%.2f/lb\n", ARTICHOKE);
    printf("b: beet       $%.2f/lb\n", BEET);
    printf("c: carrot     $%.2f/lb\n", CARROT);
    printf("q: quit.\n");
    //打印选择信息
    while ((ch = tolower(getchar())) != 'q')
    {
    //	if (ch == '\n')
    //		continue;					//滤掉回车
        switch (ch)
        {
            case 'a': printf("Input the weight of artichoke in pound: ");
                      scanf("%lf", &weight);
                      weight_artichoke += weight;
                      count++;
                      printf("Continue entering a, b, c or q: ");
                      break;
            case 'b': printf("Input the weight of beet in pound: ");
                      scanf("%lf", &weight);
                      weight_beet += weight;
                      count++;
                      printf("Continue entering a, b, c or q: ");
                      break;
            case 'c': printf("Input the weight of carrot in pound: ");
                      scanf("%lf", &weight);
                      weight_carrot += weight;
                      count++;
                      printf("Continue entering a, b, c or q: ");
                      break;
            default: printf("Please enter the right character.");
        }
        while (getchar () != '\n')
            continue;					//滤掉输入重量后面的所有字符
        
    }
    if (!count)
    {
        printf("Bye.\n");
        return 0;
    }										//开始输出q，直接退出
    total_weight = weight_artichoke + weight_beet + weight_carrot;
    veg_cost = weight_artichoke * ARTICHOKE + weight_beet * BEET
                + weight_carrot * CARROT;
    discount = 0;
    if (veg_cost >= DISCOUNT_LIMIT)
    {
        discount = veg_cost * DISCOUNT_RATE;
        order_cost = veg_cost - discount;
    }
    else
        order_cost = veg_cost;				//折扣计算
    
    if (total_weight <= BREAK1)
        pack_tran_fee = FEE1;
    else if (total_weight <= BREAK2)
        pack_tran_fee = FEE2;
    else
        pack_tran_fee = FEE2 + (total_weight - BREAK2) * FEE3_RATE;
    //装运费计算
    total_cost = order_cost + pack_tran_fee;
    
    printf("\nHere is what you choose:\n");
    if (weight_artichoke) {
        printf("artichoke   Price: $%.2f/lb  weight: %.2f pounds  cost: $%.2f\n",
                ARTICHOKE, weight_artichoke, weight_artichoke * ARTICHOKE);
    }
    if (weight_beet) {
        printf("beet        Price: $%.2f/lb  weight: %.2f pounds  cost: $%.2f\n",
                BEET, weight_beet, weight_beet * BEET);
    }
    if (weight_carrot) {
        printf("carrot      Price: $%.2f/lb  weight: %.2f pounds  cost: $%.2f\n",
                CARROT, weight_carrot, weight_carrot * CARROT);
    }
    printf("The order cost: $%.2f\n", veg_cost);

    if (discount)
        printf ("You have %%%.f discount, and the reduced money is $%.2f\n",
                DISCOUNT_RATE * 100, discount);
    printf("The packing and transpoting fee is $%.2f\n", pack_tran_fee);
    printf("The total cost is $%.2f\n", total_cost);
    //输出订单信息

    return 0;
}
    





        
