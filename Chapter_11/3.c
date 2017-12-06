#include <stdio.h>
#include <ctype.h>
#define SIZE 40
void get_words(char * ar);
int main(void)
{
    char str[SIZE];
    
    printf("Enter some characters:\n");
    get_words(str);
    puts(str);

    return 0;

}

void get_words(char * ar)
{
    char ch;

    while (isspace(ch = getchar()))
        continue;
    do
        *ar++ = ch;
    while (!isspace(ch = getchar()));
    *ar = '\0';
}
        
