#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int lower = 0, upper = 0;
    char ch;

    printf("Input some texts:\n");
    while ((ch = getchar()) != EOF)
    {
        if (islower(ch))
            lower++;
        if (isupper(ch))
            upper++;
    }
    printf("lower:%d, upper:%d\n", lower, upper);

    return 0;
}
