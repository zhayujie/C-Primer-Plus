#include <stdio.h>
#include <ctype.h>
int myatoi(char * st);
int main(void)
{
    char str[40];
    gets(str);
    printf("%d\n", myatoi(str));
}

int myatoi(char * st)
{
    int sum = 0;

    while (*st)
    {	//把字符数字逐位转化为数值
        if (isdigit(*st))
            sum = 10 * sum + (*st - '0');
        else
            return 0;		//不是纯数字则返回0
        st++;
    }

    return sum;
}
