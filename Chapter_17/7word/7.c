#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word.h"
#define LEN 40
#define SIZE 40

char get_choice(void);
char * s_gets(char * st, int n);
void count_word(Tree * pt, Item * item);
void print_word(Item temp);

int main(void)
{
    Tree words;
    Item temp;
    FILE * fp;
    char ch;
    char name[LEN];
    char word[SIZE];
    
    //打开文件
    printf("Please input the file name:\n");
    s_gets(name, LEN);
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open the file.\n");
        exit(1);
    }

    //从文件读取单词
    InitializeTree(&words);
    while (fscanf(fp, "%s", word) == 1)
    {
        strcpy(temp.word, word);
        temp.num = 1;
        AddItem(&words, &temp);
        if (TreeIsFull(&words))
        {
            fprintf(stderr, "The tree is full.\n");
            break;
        }
    }
    fclose(fp);

    while ((ch = get_choice()) != 'q')
    {
        if (ch == 'a')
        {
            if (TreeIsEmpty(&words))
                printf("There is no word.\n");
            else
                Traverse(&words, print_word);
        }
        else
            count_word(&words, &temp);
    }
    
    DeleteAll(&words);
    printf("Bye.\n");

    return 0;
}

char get_choice(void)
{
    char ch;

    printf("\na. show word list\n");
    printf("b. find a word\n");
    printf("q. quit\n");
    

    ch = getchar();
    while (strchr("abq", tolower(ch)) == NULL)
    {
        while (getchar() != '\n')
            continue;
        printf("Please input the a, b, or q.\n");
        ch = getchar();
    }
    while (getchar() != '\n')
        continue;

    return ch;
}

void print_word(Item temp)
{
    printf("word: %s\t\t\tcount: %d\n", temp.word, temp.num);
}
 
void count_word(Tree * pt, Item * item)
{
    int count;

    printf("Enter the word you want to search:\n");
    s_gets(item->word, SIZE);
    item->num = 1;
    count = ItemCount(pt, item);
    if (!count)
        printf("Can't find the word.\n");
    else
        printf("count: %d\n", ItemCount(pt, item));
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
