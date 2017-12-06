#include <stdio.h>
#include <ctype.h>
int get_ch(char ch);
int main(void)
{
    char ch;

    printf("Input some texts:\n");
    while ((ch = getchar()) != EOF)
        printf("%d ", get_ch(ch));
    return 0;
}

int get_ch(char ch)
{
    if (isalpha(ch))
        return tolower(ch) - 'a' +1;
    else
        return -1;
}
    

    
        
