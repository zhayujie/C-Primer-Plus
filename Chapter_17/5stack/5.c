#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

#define SIZE 40

char * s_gets(char * st, int n);

int main(void)
{
    Stack stack;
    Item temp[SIZE];
    Item ch;
    int i;

    InitializeStack(&stack);

    //将用户输入数据压入栈中
    printf("Enter a string:\n");
    while (s_gets(temp, SIZE) != NULL && temp[0] != '\0')
    {
        for (i = 0; temp[i] != '\0'; i++)
        {
            if (AddItem(&stack, temp[i]) == 0)
            {
                break;
            }
        }
        
        if (StackIsFull(&stack))
        {
            fprintf(stderr, "The stack is full.\n");
            break;
        }
        printf("Your next string (empty line to stop):\n");
    }

    //从栈中弹出数据并输出
    if (StackIsEmpty(&stack))
    {
        fprintf(stderr, "There is no data.\n");
        exit(1);
    }
    
    printf("You input %d charcters.\n", StackItemCount(&stack));
    printf("The string in reverse order:\n");
    while (StackIsEmpty(&stack) != 1)
    {
        DelItem(&stack, &ch);
        putchar(ch);
    }
    printf("\nBye.\n");

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
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}


