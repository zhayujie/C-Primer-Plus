#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NAMELEN 10
#define ABBLEN 4
#define MONTHS 12
    
struct month {
    char name[NAMELEN];
    char abbrev[ABBLEN];
    int days;
    int monumb;
};

struct month months[MONTHS] = {
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

int get_res(void);
void get_years(void);
int get_months(void);
int get_days(int);

int main(void)
{
    int total_days;

    total_days = get_res();
    printf("The number of days before the specified day ");
    printf("is %d\n", total_days);
    return 0;
}

//得到结果的函数
int get_res(void)
{
    int n_months;
    int n_days;
    int i;
    int total = 0;
    
    get_years();
    n_months = get_months();
    n_days = get_days(n_months);

    for (i = 0; i < n_months - 1; i++)
    {
        total += months[i].days;
    }
    total += n_days;

    return total;
}

//输入并处理年数
void get_years(void)
{
    int n_years;

    printf("Please input a particular year: ");
    while (scanf("%d", &n_years) != 1)
    {
        while (getchar() != '\n')
            continue;
        printf("Please input a integer: ");
    }
    if (n_years % 4 == 0)
        months[1].days = 29;
    else
        months[1].days = 28;
}

//输入并处理月份
int get_months(void)
{
    int n_months;

    printf("Input the month: ");
    while (scanf("%d", &n_months) != 1 || (n_months < 0 || n_months > 12))
    {
        while (getchar() != '\n')
            continue;
        printf("Please input a integer from 1 to 12: ");
    }

    return n_months;
}

//输入并处理天数
int get_days(int n)
{
    int n_days;

    printf("Input the days: ");
    while (scanf("%d", &n_days) != 1 ||
        (n_days < 1 || n_days > months[n - 1].days))
    {
        while (getchar() != '\n')
            continue;
        printf("Please input a integer from 1 to %d: ",
            months[n - 1].days);
    }

    return n_days;
}

