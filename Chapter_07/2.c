#include <stdio.h>
#define CHARS_PER_LINE 8	//每行字符数
int main(void)
{
    char ch;
    int n_chars = 1;			//字符数

    printf("Enter some characters(# to quit):\n");
    while ((ch = getchar()) != '#')
    {
        printf("%3c(%3d) ", ch, ch);
        if (n_chars++ % CHARS_PER_LINE == 0)
            printf("\n");
    }
    printf("\n");

    return 0;
}



