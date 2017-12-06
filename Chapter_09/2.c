#include <stdio.h>
void chline(char ch, int i, int j);
int main(void)
{
    int row, col;
    char ch;
    printf("Input a character you want to print: ");
    ch = getchar();
    printf("Input the number of rows and columns: ");
    scanf("%d%d", &row, &col);
    chline(ch, row, col);

    return 0;
}

void chline(char ch, int i , int j)
{
    int row, col;
    for (row = 1; row <= i; row++)
    {
        for(col = 1; col <=j; col++)
            putchar(ch);
        putchar('\n');
    }

    return;
}
