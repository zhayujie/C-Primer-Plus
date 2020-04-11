#include<stdio.h>

int main(void)
{
    char ch='A';
    char a;
    int i, j,ROW;

    printf("please input a letter:");
    scanf("%c", &a);
    ROW = a - ch + 1;
    
    for (i = 1; i <= ROW; i++)
    {
        for(j=1;j<=ROW-i;j++)
            printf(" ");
        for(j=0;j<i;j++)
            printf("%c",ch+j);
        for(j=i-2;j>=0;j--)
            printf("%c",ch+j);
        printf("\n");
    }
    return 0;
}
