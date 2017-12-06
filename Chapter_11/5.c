#include <stdio.h>
#include <string.h>
#define QUIT "quit"
#define SIZE 80
//搜索字符在字符串中首次出现的位置
char * str_ch(char * str, char c);
int main(void)
{
    char str[SIZE];
    char ch;
    char * ret_val;

    printf("Input a string (type quit to quit):\n");
    gets(str);
    while (strcmp(str, QUIT))
    {
        printf("Input a character: ");
        scanf("%c", &ch);
        while (getchar() != '\n')		//跳过剩余输入部分
            continue;
        ret_val = str_ch(str, ch);
        if (ret_val != NULL)
            printf("Find! The string start with the %c:\n"
            "%s\n", ch, ret_val);
        else
            printf("Can't find!\n");
        printf("Input a string (type quit to quit):\n");
        gets(str);
    }
    printf("Bye.\n");
        
    return 0;
}



char * str_ch(char * str, char c)
{
    int flag = 0;
    int count = 0;
    
    while (count++ < strlen(str))
        if (*str++ == c)
        {
            flag = 1;
            break;
        }
    if (flag)
        return str - 1;
    else
        return NULL;
}
