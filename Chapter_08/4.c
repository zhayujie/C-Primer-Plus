#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    int inword = 0;			//在单词中为1否则为0
    int words = 0;			//单词数
    int chars = 0;			//字符数

    printf("Please enter some words:\n");
    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch) && !ispunct(ch))
            chars++;
    //开始一个新的单词
        if (!isspace(ch) && !ispunct(ch) && !inword)
        {
            inword = 1;
            words++;
        }
    //单词末尾
        if (isspace(ch) || ispunct(ch) && inword)
            inword = 0;
    }
        printf("There are %d words and %d letters\n",
                words, chars);
        printf("The average number of letters of ");
        printf("each word is %.2f.\n",
                ((double)chars / (double)words));

        return 0;
    }




