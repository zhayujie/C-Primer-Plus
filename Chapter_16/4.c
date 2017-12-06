#include <stdio.h>
#include <time.h>

void delay(double time);

int main(void)
{
    double time;

    printf("Please input the time (in seconds) to delay"
        " (q to quit):\n");
    while (scanf("%lf", &time) == 1)
    {
        delay(time);
        printf("Time is out.\n");
        printf("Your next input (q to quit):\n");
    }

    return 0;
}

void delay(double time)
{
    double t;

    t = (double) clock() / CLOCKS_PER_SEC;
    while ((double) clock() / CLOCKS_PER_SEC - t < time)
        ;
}
