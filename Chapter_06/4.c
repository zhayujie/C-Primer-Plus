#include<stdio.h>
#define ROWS 6
int main(void)
{
    char ch;
    int i,j;
    for(ch='A',i=0;i<ROWS;i++)
    {
        for(j=0;j<=i;j++)
            printf("%c",ch++);
        printf("\n");

    }
    return 0;
}
