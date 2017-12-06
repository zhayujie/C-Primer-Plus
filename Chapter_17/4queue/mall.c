#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HOUR 60

int newcustomer(double x);
Item customertime(long when);

Queue line1;
Queue line2;
Item temp;

int hours;					//模拟的小时数
int cust_per_hour;			//平均每小时来的顾客数
int wait_time1 = 0;         //摊位1从当前到空闲的时间
int wait_time2 = 0;         //摊位2从当前到空闲的时间
long cycle;					//循环次数
long cyclelimit;			//循环的最大数
long turnaways = 0;			//被拒的顾客数
long customers = 0;			//加入队列的顾客数
long served = 0;			//接受服务的顾客数
long sum_line = 0;			//累计队列总长
long line_wait = 0;			//累计队列等候时间
double min_per_cust;		//顾客到来的平均间隔时间

int main(void)
{
    printf("Enter the number of simulation hours:\n");
    scanf("%d", &hours);
    printf("Enter the average number of customers per hour:\n");
    scanf("%d", &cust_per_hour);
    cyclelimit = MIN_PER_HOUR * hours;
    min_per_cust = MIN_PER_HOUR / cust_per_hour;

    InitializeQueue(&line1);
    InitializeQueue(&line2);
    srand((unsigned int) time(0));
    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))		//如果一分钟内有顾客来
        {
            if (QueueIsFull(&line1) && QueueIsFull(&line2))
                turnaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                if (line1.items > line2.items)
                    EnQueue(&line2, temp);
                else if (line1.items < line2.items)
                    EnQueue(&line1, temp);
                else
                    (rand() % 2) ? EnQueue(&line1, temp) : EnQueue(&line2, temp);
            }
        }

        if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
        {
            DeQueue(&line1, &temp);
            wait_time1 = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }

        if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
        {
            DeQueue(&line2, &temp);
            wait_time2 = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }

        if (wait_time1 > 0)
            wait_time1--;

        if (wait_time2 > 0)
            wait_time2--;

        sum_line += (long) QueueItemCount(&line1)
            + (long) QueueItemCount(&line2);
    }

    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("         turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n", (double) sum_line / cyclelimit);
        printf(" average wait time: %.2f minutes\n", (double) line_wait / served);
    }
    else
        puts("No customers!");
    DeleteAll(&line1);
    DeleteAll(&line2);
    puts("Bye!");

    return 0;
}

//一分钟之内有顾客来，返回1
int newcustomer(double x)
{
    if (x * rand() / RAND_MAX < 1)
        return 1;
    else
        return 0;
}

Item customertime(long when)
{
    Item cust;

    cust.arrive = when;
    cust.processtime = rand() % 3 + 1;

    return cust;
}

