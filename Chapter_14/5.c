#include <stdio.h>
#define LEN 10
#define NUM 3
#define CSIZE 4
#define N_SCORES 3

struct name {
    char first_name[LEN];
    char last_name[LEN];
};

struct student {
    struct name names;
    float grade[NUM];
    float average;
};

void get_score(struct student info[], int n);
void get_aver(struct student info[], int n);
void print_info(struct student info[], int n);
void get_all_aver(struct student info[], int n);

int main(void)
{
    struct student score[CSIZE] = {
        {{"Zha", "Yujie"}, {0, 0, 0}, 0},
        {{"Jiang", "Wenjie"}, {0, 0, 0}, 0},
        {{"Liu", "Chengming"}, {0, 0, 0}, 0},
        {{"Pan", "Xiangxiang"}, {0, 0, 0}, 0}
    };
    get_score(score, CSIZE);
    get_aver(score, CSIZE);
    print_info(score, CSIZE);
    get_all_aver(score, CSIZE);
    
    return 0;
}

void get_score(struct student info[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("Input the scores of 3 courses of %s %s\n",
            info[i].names.first_name, info[i].names.last_name);
        for (j = 0; j < N_SCORES; j++)
        {
            scanf("%f", &info[i].grade[j]);
        }
    }
}
        
void get_aver(struct student info[], int n)
{

    int i, j;
    float sum;

    for (i = 0; i < n; i++)
    {
        for (j = 0, sum = 0.0; j < N_SCORES; j++)
        {
            sum += info[i].grade[j];
        }
        info[i].average = sum / N_SCORES;
    }
}

void print_info(struct student info[], int n)
{
    int i, j;

    printf("    Name%15s %s %s  average\n", "score1",
        "score2", "score3");
    for (i = 0; i < n; i++)
    {
        printf("%5s%-10s  ", info[i].names.first_name,
            info[i].names.last_name);
        for (j = 0; j < N_SCORES; j++)
            printf("%6g", info[i].grade[j]);
        printf("%11.2f\n", info[i].average);
    }
}

void get_all_aver(struct student info[], int n)
{
    int i;
    float total = 0;

    for (i = 0; i < n; i++)
    {
        total += info[i].average;
    }
        printf("The average score of all students is %.2f.\n",
            total / CSIZE);
}
