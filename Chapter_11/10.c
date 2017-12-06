#include <stdio.h>
#define SIZE 40
char * s_gets(char * st, int n);
void delete_space(char * st);
int main(void)
{
    char str[SIZE];
    while (*s_gets(str, SIZE) != '\n')
        delete_space(str);
    printf("Bye.\n");
    
    return 0;
}

//删除空格的函数
void delete_space(char * st)
{
    int i;
    char * p = st;
    
    printf("\nThe original string is:\n");
    puts(st);
    while (*st)
    {	//如果遇到空格，后面所有字符往前进一格
        if (*st == ' ')
            for (i = 0; st[i] != '\0'; i++)
                st[i] = st[i + 1];
        else
            st++;
    }
    printf("Now, the string is:\n");
    puts(p);
    printf("\n");
}

//自定义的字符串输入函数
char * s_gets(char * st, int n)
{
    int i = 0;
    
    printf("Input the first string (blank line to quit):\n");
    if (fgets(st, n, stdin) != NULL && st[0] != '\n')	//即返回值st不等于NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return st;
}
