#include <stdio.h>
int main(void)
{
    char ch;
    char last_ch = 0;		 //前一个字符
    int count=0;

    printf("Enter some texts(# to quit):\n");
    while ((ch = getchar()) != '#')
    {
        if ((ch == 'i') && (last_ch == 'e'))
            count++;
        last_ch = ch;		//出现ei时，计数+1
    }
    printf("\"ei\" appeared %d times.\n", count);
    
    return 0;
}


