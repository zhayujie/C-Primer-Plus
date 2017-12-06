#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 40
char * * mal_ar(int n);
int main(void)
{
    int words, i;
    char * * st;
    
    printf("How many words do you wish to enter? ");
    scanf("%d", &words);
    getchar();					//滤掉回车
    printf("Enter %d words now:\n", words);
    st = mal_ar(words);
    printf("Here are your words:\n");
    for (i = 0; i < words; i++)
    {
        puts(st[i]);
        free(st[i]);	//释放每个指针指向的内存
    }
    free(st);			//释放指针数组

    return 0;
}

char * * mal_ar(int n)
{
    char * * pt;
    int i, j;
    char ch;

    //给n个指针分配动态内存空间，返回指针的指针
    pt = (char * *)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        //给每个指针指向的地址分配内存空间
        pt[i] = (char *)malloc(SIZE * sizeof(char));
        //可以仅用scanf("%s", pt[i]);
        while (isspace(ch = getchar()))				//处理单词之前的空格符
            continue;
        pt[i][0] = ch;								//单词首字符
        j = 1;
        while (!isspace(pt[i][j] = getchar()))
            j++;
        pt[i][j] = '\0';							//将末尾的空格替换为\0'
    }

    return pt;
}
