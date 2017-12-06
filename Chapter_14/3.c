#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void sort_by_input(const struct book library[], int n);
void sort_by_title(struct book library[], int n);
void sort_by_price(struct book library[], int n);
char * s_gets(char * st, int n);

int main(void)
{
    static struct book library[MAXBKS];
    int count = 0;

    printf("Please enter the book title (empty line to stop):\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
        && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXTITL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0)
    {
        printf("The list of books in order of your input:\n");
        sort_by_input(library, count);
        printf("The list of books in order of title:\n");
        sort_by_title(library, count);
        printf("The list of books in order of price:\n");
        sort_by_price(library, count);
    }
    
    return 0;
}

void sort_by_input(const struct book library[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%s by %s: $%.2f\n", library[i].title,
            library[i].author, library[i].value);
    printf("\n");
}

void sort_by_title(struct book library[], int n)
{
    int i, j;
    struct book temp;
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
            if (strcmp(library[i].title, library[j].title) > 0)
            {
                temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
    }
    for (i = 0; i < n; i++)
        printf("%s by %s: $%.2f\n", library[i].title,
            library[i].author, library[i].value);
    printf("\n");
}

void sort_by_price(struct book library[], int n)
{
    int i, j;
    struct book temp;
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
            if (library[i].value > library[j].value)
            {
                temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
    }
    for (i = 0; i < n; i++)
        printf("%s by %s: $%.2f\n", library[i].title,
            library[i].author, library[i].value);
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
