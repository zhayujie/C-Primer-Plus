#include <stdio.h>
#include <string.h>
#define SIZE 40
#define QUIT "quit"
char * s_gets(char * st, int n);
void reverse(char * st);
int main(void)
{
    char str[SIZE];
    while (strcmp(s_gets(str, SIZE), QUIT))		//输入quit结束
    {
        reverse(str);
        puts(str);
    }
    
    return 0;
}


//自定义的字符串输入函数
char * s_gets(char * st, int n)
{
    int i = 0;
    
    printf("Input the first string (type quit to quit):\n");
    if (fgets(st, n, stdin))	//即返回值st不等于NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return st;
}

//使字符串倒序的函数
void reverse(char * st)
{
    unsigned int i;
    char temp;

    size_t length = strlen(st);
    for (i = 0; i < length / 2; i++)
    {
        temp = st[length - i -1];
        st[length - i - 1] = st[i];
        st[i] = temp;
    }
    st[length] = '\0';
}





    

