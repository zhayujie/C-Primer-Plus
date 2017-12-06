#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NAMELEN 10
#define ABBLEN 4
#define MONTHS 12
char * s_gets(char * st, int n);
int get_days(char * st);

struct month {
    char name[NAMELEN];
    char abbrev[ABBLEN];
    int days;
    int monumb;
};

struct month months[12] = {
    {"january", "jan", 31, 1},
    {"february", "feb", 28, 2},
    {"march", "mar", 31, 3},
    {"april", "apr", 30, 4},
    {"may", "may", 31, 5},
    {"june", "jun", 30, 6},
    {"july", "jul", 31, 7},
    {"august", "aug", 31, 8},
    {"september", "sep", 30, 9},
    {"october", "oct", 31, 10},
    {"november", "nov", 30, 11},
    {"december", "dec", 31, 12}
};

int main(void)
{
    char st[NAMELEN];

    printf("Please input the month name (empty line to quit):\n");
    while (s_gets(st, NAMELEN) != NULL && st[0] != '\0')
    {
        if (get_days(st) == 0)
            printf("The month name is wrong.\n");
        else
        printf("The days untill %s: %d\n", st, get_days(st));
        printf("Next input (empty line to quit):\n");
    }

    printf("Bye.\n");
    return 0;
}


int get_days(char * st)
{
    int total = 0;
    int i = 0;
    int count;
    
    while (st[i])
    {
        st[i] = tolower(st[i]);
        i++;
    }

    for (i = 0; i < MONTHS; i++)
    {
        if (strcmp(st, months[i].name) == 0)
            break;
    }
    if (i < MONTHS)
    {
        for (count = 0; count <= i; count++)
            total += months[count].days;
    }

    return total;
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
