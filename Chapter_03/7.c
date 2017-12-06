#include<stdio.h>
int main(void)
{
    float inches,cms;
    printf("input your height(inch): ");
    scanf("%f",&inches);
    cms=inches*2.54;
    printf("your height(cm): %f\n",cms);

    return 0;
}
