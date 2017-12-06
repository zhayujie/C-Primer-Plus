#include <stdio.h>
#include <stdlib.h>
#define LEN 40
#define ROW 20
#define COL 30
int main(void)
{
    FILE * fs, * fd;				//fs指向源文件,fd指向目标文件
    char name[LEN];
    char digit[ROW][COL];
    char result[ROW][COL + 1];
    char ch[] = {" .':~*= %#"};		//数字字符对应的符号
    int i, j;

    printf("Please enter the source file name:\n");
    gets(name);
    //打开源文件
    if ((fs = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Could not open %s.", name);
        exit(EXIT_FAILURE);
    }
    //将文件内容读入 20 * 30 的int数组中
    //并且转化成相应符号放入 20 * 31 的字符数组中
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            fscanf(fs, "%d", &digit[i][j]);
            result[i][j] = ch[digit[i][j]];
        }
        result[i][j] = '\0';
    }
    printf("Enter the destination file name:\n");
    gets(name);
    //打开目标文件
    if ((fd = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Could not open %s.", name);
        exit(EXIT_FAILURE);
    }
    //将结果打印出来并写入目标文件
    for (i = 0; i < ROW; i++)
    {
        fprintf(stdout, "%s\n", result[i]);
        fprintf(fd, "%s\n", result[i]);
    }
    //关闭文件
    if (fclose(fs) != 0 || fclose(fd) != 0)
        fprintf(stderr, "Error for closing file.\n");

    return 0;
}
