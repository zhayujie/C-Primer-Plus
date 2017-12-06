#include <stdio.h>
#include <string.h>
#define QUIT "quit"
#define SIZE 80
//搜索字符在字符串中首次出现的位置
int is_within(char * str, char c);
int main(void)
{
    char str[SIZE];
    char ch;

    printf("Input a string (type quit to quit):\n");
    while (strcmp(gets(str), QUIT))
    {
        printf("Input a character: ");
        scanf("%c", &ch);
        while (getchar() != '\n')		//跳过剩余输入部分
            continue;
        if (is_within(str, ch))
            printf("Find!\n");
        else
            printf("Can't find!\n");
        printf("Input a string (type quit to quit):\n");
    }
    printf("Bye.\n");
        
    return 0;
}



int is_within(char * str, char c)
{
    int flag = 0;
    size_t count = 0;
    
    while (count++ < strlen(str))
        if (*str++ == c)
        {
            flag = 1;
            break;
        }

    return flag;
}
