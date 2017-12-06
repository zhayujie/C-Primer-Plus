#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
#define SLEN 81
char * s_gets(char * st, int n);

int main(void)
{
    FILE * f1, * f2;
    char name_f1[SIZE];
    char name_f2[SIZE];
    char ch1, ch2;

    //依次输入两个文件的文件名
    fprintf(stdout, "Please enter the first file name:\n");
    s_gets(name_f1, SIZE);
    fprintf(stdout, "Please enter the second file name:\n");
    s_gets(name_f2, SIZE);
    
    //依次输入两个文件
    if ((f1 = fopen(name_f1, "r")) == NULL)
    {
        fprintf(stderr, "Could not open the %s\n", name_f1);
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen(name_f2, "r")) == NULL)
    {
        fprintf(stderr, "Could not open the %s\n", name_f2);
        exit(EXIT_FAILURE);
    }
    
    do
    {
        while ((ch1 = getc(f1)) != EOF && ch1 != '\n')
        {
            putchar(ch1);
        }
        while ((ch2 = getc(f2)) != EOF && ch2 != '\n')
        {
            putchar(ch2);
        }
        putchar('\n');
    }
    while (ch1 != EOF || ch2 != EOF);

    fclose(f1);
    fclose(f2);

    return 0;
}

//自定义读取文件名的函数
char * s_gets(char * st, int n)
{
    char * find;
    char * ret_val;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');	 		//查找换行符
        if (find)
            *find = '\0';					//替换为空字符
        else
            while (getchar() != '\n')
                continue;					//处理多余输入
    }

    return ret_val;
}
