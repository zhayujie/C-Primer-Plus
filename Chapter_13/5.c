//命令行参数argv[1]代表目标文件名，后面几个为源文件名
//该程序把多个源文件加到源文件末尾
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE * source, FILE * dest);
char * s_gets(char * st, int n);

int main(int argc, char * argv[])
{
    FILE * fs, * fa;		//fs指向源文件,fa指向目标文件
    int i;
    int files = 0;
    char ch;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fa = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't creat output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    for (i = 2; i < argc; i++)
    {
        if (strcmp(argv[1], argv[i]) == 0)
        {
            fputs("Can't append file to itself\n", stderr);
        }
        else if ((fs = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Could not open %s.\n", argv[i]);
        }
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't creat input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", argv[i]);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", argv[1]);
            fclose(fs);
            printf("File %s appended.\n", argv[i]);
        }
    }
    printf("%s contents:\n", argv[1]);
    rewind(fa);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

//附加文件的函数
void append(FILE * source, FILE * dest)
{
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
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
