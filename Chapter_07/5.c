#include <stdio.h>
int main(void)
{
    char ch;
    int n_repl = 0;				//替换次数
    
    printf("Enter some texts(# to quit):\n");
    while ((ch = getchar()) != '#') {
        switch (ch)
        {
            case '.': ch = '!';
                      n_repl++;
                      break;
            case '!': printf("!");
                      n_repl++;
                      break;
            default: break;
        }						//利用switch语句进行替换
        printf("%c",ch);
    }
    printf("\n%d substitutions were made.\n", n_repl);

    return 0;
}



