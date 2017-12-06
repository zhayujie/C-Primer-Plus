#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
char * s_gets(char * st, int n);

int main(void)
{
    FILE * fs, * fa;		//fs指向源文件,fa指向目标文件
    char ch;
    char name_source[SIZE];
    char name_dest[SIZE];
    int count = 0;

    //输入源文件和目标文件名
    fprintf(stdout, "Please enter the source file name:\n");
    s_gets(name_source, SIZE);
    fprintf(stdout, "Please enter the destination file name:\n");
    s_gets(name_dest, SIZE);
    
    //打开源文件和目标文件
    if ((fs = fopen(name_source, "r")) == NULL)
    {
        fprintf(stderr, "Could not open the %s\n", name_source);
        exit(EXIT_FAILURE);
    }
    if ((fa = fopen(name_dest, "w")) == NULL)
    {
        fprintf(stderr, "Could not open the %s\n", name_dest);
        exit(EXIT_FAILURE);
    }

    //将源文件每3个字符的第1个字符输出到目标文件
    while ((ch = getc(fs)) != EOF)
    {
        if (count++ %3 == 0)
            putc(ch, fa);
    }

    //收尾工作
    if (fclose(fs) != 0 || fclose(fa) != 0)
        fprintf(stderr, "Error in closing files\n");

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
            *find = '\0';			//替换为空字符
        else
            while (getchar() != '\n')
                continue;		//处理多余输入
    }

    return ret_val;
}

