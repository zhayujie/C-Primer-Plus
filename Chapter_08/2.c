#include <stdio.h>
#define SPACE 32
#define CTRL 64
#define COL 10				//每行打印10对
int main(void)
{
    char ch;
    int count = 0;

    while ((ch = getchar()) != EOF)
    {
        count++;
    //打印字符输出
        if (ch >= SPACE)
            printf("%c ", ch);
    //换行符和制表符的输出
        else if (ch == '\n' || ch == '\t')
            printf("%s", ch == '\n' ? "\\n" : "\\t");
    //一般控制字符的输出
        else
            printf("^%c", ch + CTRL);
        printf("%-5d", ch);
        if (ch == '\n')
            count = 0;
        if (count % COL == 0)	//10对换行
            printf("\n");
    }

    return 0;
}

    



