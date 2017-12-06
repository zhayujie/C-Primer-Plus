#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 40
char * s_gets(char * st, int n);

int main(void)
{
    FILE * fs;			//原始文件指针
    FILE * ft;			//目标文件指针
    char name_s[SIZE];
    char name_t[SIZE];
    char ch;
    
    //输入原始文件和目标文件名
    fprintf(stdout, "Please enter the source file name:\n");
    s_gets(name_s, SIZE);
    fprintf(stdout, "Please enter the target file name:\n");
    s_gets(name_t, SIZE);
    
    //打开原始文件和目标文件
    if ((fs = fopen(name_s, "r")) == NULL)
        fprintf(stderr, "Could not open the %s\n", name_s);
    if ((ft = fopen(name_t, "w")) == NULL)
        fprintf(stderr, "Could not open the %s\n", name_t);
    
    //拷贝数据
    while ((ch = getc(fs)) != EOF)
        putc(toupper(ch), ft);
    
    fclose(fs);
    fclose(ft);

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
        find = strchr(st, '\n');	//查找换行符
        if (find)
            *find = '\0';			//替换为空字符
        else
            while (getchar() != '\n')
                continue;			//处理多余输入
    }

    return ret_val;
}
