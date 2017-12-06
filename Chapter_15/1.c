#include <stdio.h>
#include <string.h>
int btoi(char * st);
int main(void)
{
    char * pbin = "01001001";
    
    printf("The decimal number: %d.\n", btoi(pbin));
    
    return 0;
}

int btoi(char * st)
{
    int num = 0;

    while (*st)
        num = (num << 1) + (*st++ - '0');

    return num;
}
