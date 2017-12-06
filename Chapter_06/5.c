#include<stdio.h>
#define ROWS 5
int main(void)
{
    char ch='A';
    int i,j;
    for(i=1;i<=ROWS;i++)
    {
        for(j=1;j<=ROWS-i;j++)
            printf(" ");
        for(j=0;j<i;j++)
            printf("%c",ch+j);
        for(j=i-2;j>=0;j--)
            printf("%c",ch+j);
        printf("\n");
    }
    return 0;
}
