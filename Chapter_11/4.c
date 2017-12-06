#include <stdio.h>
#include <ctype.h>
#define SIZE 10
void get_words(char * ar, int n);
int main(void)
{
    char str[SIZE];
    
    printf("Enter some characters:\n");
    get_words(str, SIZE);
    puts(str);

    return 0;

}

void get_words(char * ar, int n)
{
    char ch;
    int i = 0;

    while (isspace(ch = getchar()))
        continue;
    do
    {
        *(ar + i) = ch;
        i++;
    }
    while (!isspace(ch = getchar()) && i < (n - 1));
    *(ar + i) = '\0';
}
        
