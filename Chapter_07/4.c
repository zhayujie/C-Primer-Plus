#include <stdio.h>
int main(void)
{
    char ch;
    int n_repl = 0;         //替换次数
    
    printf("Enter some texts(# to quit):\n");
    while ((ch = getchar()) != '#') {
        if (ch == '.')
        {
            ch = '!';
            n_repl++;
        }					//替换句号
        else if (ch == '!')
        {
            printf("!");
            n_repl++;
        }					//替换感叹号
        printf("%c", ch);
    }
    printf("\n%d substitutions were made.\n", n_repl);
    
    return 0;
}
