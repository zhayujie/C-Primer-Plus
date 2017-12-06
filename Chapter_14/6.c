#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 10
#define NLEN 20
#define SIZE 20

struct member {
    int num;
    char fname[LEN];
    char lname[LEN];
    int play;
    int hit;
    int walk;
    int rbi;
};

void get_initial_val(struct member *, int n);
void get_data(struct member *, int n);
void print_info(struct member *, int n);

int main(void)
{
    static struct member members[SIZE];

    get_initial_val(members, SIZE);
    get_data(members, SIZE);
    print_info(members, SIZE);

    return 0;
}
    
void get_initial_val(struct member * pst, int n)
{
    int i;

    for (i = 0; i < n; i++, pst++)
    {
        pst->num = 0;
        strcpy(pst->fname, "");
        strcpy(pst->lname, "");
        pst->play = 0;
        pst->hit = 0;
        pst->walk = 0;
        pst->rbi = 0;
    }
}

void get_data(struct member * pst, int n)
{
    int number, play_times, hit_times, walk_times, rbi_num;
    FILE * fp;
    char name[NLEN];
    char f_name[LEN], l_name[LEN];

    printf("Please enter the file name: ");
    scanf("%s", name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%d%s%s%d%d%d%d", &number, f_name, l_name,
        &play_times, &hit_times, &walk_times, &rbi_num) == 7)
    {
        pst[number].num = number;
        strcpy(pst[number].fname, f_name);
        strcpy(pst[number].lname, l_name);
        pst[number].play += play_times;
        pst[number].hit += hit_times;
        pst[number].walk += walk_times;
        pst[number].rbi += rbi_num;
    }
    fclose(fp);
}

void print_info(struct member * pst, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (pst[i].fname[0] != '\0')
        {
            printf("%d %s %s %d %d %d %d", pst[i].num, pst[i].fname, pst[i].lname,
                    pst[i].play, pst[i].hit, pst[i].walk, pst[i].rbi);
            printf("\n");
        }
        else
            break;
    }
}


    
