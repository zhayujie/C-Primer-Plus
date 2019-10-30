#include <stdio.h>
#include <string.h>
#define WORD_SIZE 26
int main (void)
{
    char word[WORD_SIZE];
    printf("Input a word:\n");
    scanf("%s", word);
    for(long i = strlen(word); i >= 0; i--) {
        printf("%c", word[i]);
    }
    printf("\n");
    return 0;
}
