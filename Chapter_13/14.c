#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LEN 40
#define ROW 20
#define COL 30
int main(void)
{
    FILE * fs, * fd;				//fs指向源文件,fd指向目标文件
    char name[LEN];
    char dig[ROW][COL];
    char res[ROW][COL + 1];
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
            fscanf(fs, "%d", &dig[i][j]);
        }
    }
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if ((i == 0 && j == 0) || (i == 0 && j == 29)
                ||(i == 19 && j == 0) || (i == 19 && j == 29))
                ;
            else if (i == 0) {
                if ((abs(dig[i][j] - dig[i][j - 1]) > 1) && (abs(dig[i][j] - dig[i][j + 1]) > 1) &&
                    (abs(dig[i][j] - dig[i + 1][j]) > 1))
                    dig[i][j] = (dig[i][j - 1] + dig[i][j + 1] + dig[i + 1][j]) / 3.0 + 0.5;
            }
            else if (j == 0) {
                if ((abs(dig[i][j] - dig[i - 1][j]) > 1) && (abs(dig[i][j] - dig[i][j + 1]) > 1) &&
                    (abs(dig[i][j] - dig[i + 1][j]) > 1))
                    dig[i][j] = (dig[i - 1][j] + dig[i][j + 1] + dig[i + 1][j]) / 3.0 + 0.5;
            }

            else if (i == 19) {
                if ((abs(dig[i][j] - dig[i][j - 1]) > 1) && abs((dig[i][j] - dig[i][j + 1]) > 1) &&
                    (abs(dig[i][j] - dig[i - 1][j]) > 1))
                    dig[i][j] = (dig[i - 1][j] + dig[i][j - 1] + dig[i][j + 1]) / 3.0 + 0.5;
            }

            else if (j == 29) {
                if ((abs(dig[i][j] - dig[i][j - 1]) > 1) && (abs(dig[i][j] - dig[i + 1][j]) > 1) &&
                    (abs(dig[i][j] - dig[i - 1][j]) > 1))
                    dig[i][j] = (dig[i - 1][j] + dig[i][j - 1] + dig[i + 1][j]) / 3.0 + 0.5;
            }
            
            else {
                if ((abs(dig[i][j] - dig[i][j - 1]) > 1) && (abs(dig[i][j] - dig[i][j + 1]) > 1) &&
                    (abs(dig[i][j] - dig[i - 1][j]) > 1) && (abs(dig[i][j] - dig[i + 1][j]) > 1))
                    dig[i][j] = (dig[i - 1][j] + dig[i + 1][j] + dig[i][j - 1] + dig[i][j + 1]) / 4.0 + 0.5;
            }
        }
    }

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            res[i][j] = ch[dig[i][j]];
        }
        res[i][j] = '\0';
    }
    printf("Enter the destination file name:\n");
    gets(name);
    //打开目标文件
    if ((fd = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", name);
        exit(EXIT_FAILURE);
    }
    //将结果打印出来并写入目标文件
    for (i = 0; i < ROW; i++)
    {
        fprintf(stdout, "%s\n", res[i]);
        fprintf(fd, "%s\n", res[i]);
    }
    //关闭文件
    if (fclose(fs) != 0 || fclose(fd) != 0)
        fprintf(stderr, "Error for closing file.\n");

    return 0;
}
