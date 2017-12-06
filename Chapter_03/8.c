#include<stdio.h>
int main(void)
{
    float pint,ounce,soupspoon,teaspoon,cup;
    
    printf("input the number of cups: ");
    scanf("%f",&cup);
    pint=cup/2;
    ounce=cup*8;
    soupspoon=ounce*2;
    teaspoon=soupspoon*3;
    printf("they are equivalent of:\n%f pint\n%f ounce\n%f soupspoons\n%f teaspoons\n",pint,ounce,soupspoon,teaspoon);

    return 0;
}

