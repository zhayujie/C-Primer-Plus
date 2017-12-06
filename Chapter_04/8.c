#include<stdio.h>
#define GALLON 3.758 //1 gallon=3.785 liters
#define MILE 1.609 //1 mile=1.609 kilometers
int main(void)
{
    float gallon,mile;
    printf("Input miles and gallons: ");
    scanf("%f%f",&mile,&gallon);
    printf("Miles per gallon: %.1f\n",mile/gallon);
    printf("Litre per 100 kilometers: %.1f\n",
    gallon*GALLON/(mile*MILE)*100);
    return 0;
}
