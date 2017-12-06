#include <stdio.h>
#include <stdlib.h>
#define SIZE 256
int main(int argc, char * argv[])
{
    FILE * fs;		//原始文件指针
    FILE * fa;		//目标文件指针
    char temp[SIZE];
    size_t bytes;

    //检查命令行参数
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //以读模式打开原始文件
    if ((fs = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    //以读写模式打开目标文件
    if ((fa = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    //拷贝数据
    {
        while ((bytes = fread(temp, sizeof(char), SIZE, fs)) > 0)
            fwrite(temp, sizeof(char), bytes, fa);
    }

    fclose(fs);
    fclose(fa);

    return 0;
}



