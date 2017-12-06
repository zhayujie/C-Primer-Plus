#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
#define SIZE 4

char * s_gets(char * st, int n);
char get_choice(void);
void ToUpper(char * st);
void ToLower(char * st);
void Transpos(char * st);
void Dummy(char * st);

int main(void)
{
    char st[LEN];
    char copy[LEN];
    char ch;
    //函数指针数组
    void(*fp[SIZE])(char *) = {ToUpper, ToLower, Transpos, Dummy};
    int index;

    puts("Enter a string (empty line to quit):");
    while (s_gets(st, LEN) != NULL && st[0] != '\0')
    {
        while ((ch = get_choice()) != 'q')
        {
            switch (ch)
            {
            case 'a': index = 0; break;
            case 'b': index = 1; break;
            case 'c': index = 2; break;
            case 'd': index = 3; break;
            default : printf("Program error.\n");  break;
            }
            strcpy(copy, st);
            (*(fp[index]))(copy);
            puts(copy);
        }
        printf("Enter a string (empty line to quit):\n");
    }
    puts("Bye.");

    return 0;
}

char get_choice(void)
{
    char ch;

    printf("To choose a function, enter its letter labal:\n");
    printf("a). upper             b). lower\n");
    printf("c). transposed        d). original\n");
    printf("q). quit.\n");
    while ((ch = getchar()) < 'a' || ch > 'd' && ch != 'q')
    {
        while (getchar() != '\n')
            continue;
        printf("Please input the right letter (a, b, c, d or q).\n");
    }
    while (getchar() != '\n')
        continue;

    return ch;
}

void ToUpper(char * st)
{
    while (*st)
    {
        *st = toupper(*st);
        st++;
    }
}

void ToLower(char * st)
{
    while (*st)
    {
        *st = tolower(*st);
        st++;
    }
}

void Transpos(char * st)
{
    while (*st)
    {
        if (islower(*st))
            *st = toupper(*st);
        else if (isupper(*st))
            *st = tolower(*st);
        st++;
    }
}

void Dummy(char * st)
{

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
