#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pet.h"

char get_choice(void);
char * s_gets(char * st, int n);
void addpet(Tree * pt);
void printpet(Item temp);
void findpet(const Tree * pt);
void droppet(Tree * pt);
void showpet(const Tree * pt);

int main(void)
{
    Tree pet;
    char ch;

    InitializeTree(&pet);
    while ((ch = get_choice()) != 'q')
    {
        switch (ch)
        {
        case 'a': addpet(&pet);
            break;
        case 'l': showpet(&pet);
            break;
        case 'f': findpet(&pet);
            break;
        case 'n': printf("%d pets in club.\n",
            TreeItemCount(&pet));
            break;
        case 'd': droppet(&pet);
            break;
        default: puts("Swithing error");
        }
        printf("\n");
    }
    
    DeleteAll(&pet);
    printf("Bye.\n");

    return 0;
}

char get_choice(void)
{
    char ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet        l) show list of pets");
    puts("n) number of pets   f) find pets");
    puts("d) delete a pet     q) quit");
    

    ch = getchar();
    while (strchr("alnfdq", tolower(ch)) == NULL)
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

void showpet(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        printf("No pet in club.\n");
    else
        Traverse(pt, printpet);
}

void findpet(const Tree * pt)
{
    Item temp;
    
    if (TreeIsEmpty(pt))
        puts("No pet in the club.\n");
    else
    {
        printf("Enter the name of pet:\n");
        s_gets(temp.name, LEN);
        FindItem(pt, &temp);
    }
}
    
void addpet(Tree * pt)
{
    Item temp;
    
    if (TreeIsFull(pt))
        puts("No room in the club.\n");
    else
    {
        printf("Enter the name of pet:\n");
        s_gets(temp.name, LEN);
        printf("Enter the kind of pet:\n");
        s_gets(temp.kind[0], LEN);
        temp.num = 1;
        AddItem(pt, &temp);
    }
}

void droppet(Tree * pt)
{
    Item temp;

    if (TreeIsEmpty(pt))
    {
        puts("No entries.\n");
        return;
    }
    
    printf("Enter the name of pet:\n");
    s_gets(temp.name, LEN);
    if (DelItem(pt, &temp) == 0)
    {
        printf("Can't find the pet.\n");
    }
}

void printpet(Item temp)
{
    int i;

    printf("name: %s\t\tkind: ", temp.name);
    for (i = 0; i < temp.num; i++)
        printf("%s ", temp.kind[i]);
    printf("\n");
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
