#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 5

int btoi(char * st);				//二进制字符串转化为整数的函数
char * itob(char * st, int n);		//整数转化为二进制字符串的函数
void show_bstr(const char * st);	//4位一组显示二进制字符串

int main(int argc, char * argv[])
{
    int num1, num2;
    char bin_st[CHAR_BIT * sizeof(int) + 1];

    if (argc != 3)
    {
        fprintf(stderr, "The number of arguments is wrong.\n");
        exit(EXIT_FAILURE);
    }
    num1 = btoi(argv[1]);
    num2 = btoi(argv[2]);
    show_bstr(itob(bin_st, ~num1));
    show_bstr(itob(bin_st, ~num2));
    show_bstr(itob(bin_st, num1 & num2));
    show_bstr(itob(bin_st, num1 | num2));
    show_bstr(itob(bin_st, num1 ^ num2));

    return 0;
}

int btoi(char * st)
{
    int num = 0;

    while (*st)
        num = (num << 1) + (*st++ - '0');

    return num;
}

char * itob(char * st, int n)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    
    for (i = size - 1; i >= 0; i--, n >>= 1)
        st[i] = (01 & n) + '0';
    st[size] = '\0';

    return st;
}

void show_bstr(const char * st)
{
    int i = 0;

    while (st[i])
    {
        putchar(st[i]);
        if (++i % 4 == 0 && st[i])
            putchar(' ');
    }
    printf("\n");
}
