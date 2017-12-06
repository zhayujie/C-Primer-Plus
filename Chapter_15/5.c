#include <stdio.h>
#include <limits.h>
#define MASK 01
#define SIZE CHAR_BIT * sizeof(unsigned int)

char * itob(char * st, unsigned int n);
void show_bstr(const char * st);
unsigned int move_left(unsigned int, int);
int main(void)
{
    unsigned int num;
    int bit;
    char st[SIZE + 1];

    printf("Please input a integer and the number of bits to move:\n");
    scanf("%u%d", &num, &bit);
    printf("The original binary string:\n");
    show_bstr(itob(st, num));
    //把所有位向左移动
    num = move_left(num, bit);
    printf("The present binary string:\n");
    show_bstr(itob(st, num));
}

unsigned int move_left(unsigned int n, int bit)
{
    int i;
    
    for (i = 0; i < bit; i++)
    {
        n = (n << 1) + ((n >> (SIZE - 1)) & MASK);
    }

    return n;
}

char * itob(char * st, unsigned int n)
{
    int i;
    
    for (i = SIZE - 1; i >= 0; i--, n >>= 1)
        st[i] = (01 & n) + '0';
    st[SIZE] = '\0';

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
    
