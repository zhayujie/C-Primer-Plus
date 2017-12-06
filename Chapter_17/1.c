#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

typedef struct film {
    char title[TSIZE];
    int rating;
    struct film * prev;
    struct film * next;
} Node;

char * s_gets(char * st, int n);

int main(void)
{
    Node * head = NULL;
    Node * pre = NULL;
    Node * end;
    Node * current;
    char input[TSIZE];

    //储存信息
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (Node *) malloc(sizeof(Node));
        if (head == NULL)
            head = current;
        else
        {
            pre->next = current;
        }
        current->prev = pre;
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty to stop):");
        pre = current;
    }
    end = pre;

    if (head == NULL)
    {
        fprintf(stderr, "No data entered.\n");
        exit(1);
    }
    else
        printf("Here is the movie list in positive order:\n");

    //正序显示电影列表
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s  Rating: %d\n", current->title,
            current->rating);
        current = current->next;
    }

    //逆序显示电影列表
    printf("Here is the movie list in reverse order:\n");
    current = end;
    while (current != NULL)
    {
        printf("Movie: %s  Rating: %d\n", current->title,
            current->rating);
        current = current->prev;
    }

    return 0;
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
            while(getchar() != '\n')
                continue;
    }

    return ret_val;
}
