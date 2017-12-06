#include <stdio.h>
int main(void)
{
    char ch;
    int n_space = 0;		//空格数
    int n_newline = 0;		//换行数
    int n_others = 0;		//其他字符数
    
    printf("Enter some text; Enter # to quit.\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            n_space++;
        else if (ch == '\n')
            n_newline++;
        else
            n_others++;
    }
    printf("Spaces: %d, newlines: %d, others: %d\n",
            n_space, n_newline, n_others);

    return 0;
}
