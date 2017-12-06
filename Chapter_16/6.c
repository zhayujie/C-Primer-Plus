#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
#define NUM 5

struct names {
    char first[SIZE];
    char last[SIZE];
};

int comp(const void * p1, const void * p2);

int main(void)
{
    int i;

    struct names staff[NUM] = {
        {"zha", "yujie"},
        {"xia", "yufeng"},
        {"bu", "jianqiang"},
        {"xu", "feifan"},
        {"ding","bing"}
    };

    qsort(staff, NUM, sizeof(struct names), comp);
    for (i = 0; i < NUM; i++)
    {
        printf("%s %s\n", staff[i].first, staff[i].last);
    }

    return 0;
}

int comp(const void * p1, const void * p2)
{
    const struct names *ps1 = (const struct names *) p1;
    const struct names *ps2 = (const struct names *) p2;
    int res;
    res = strcmp(ps1->first, ps2->first);
    if (res)
        return res;
    else
        return strcmp(ps1->last, ps2->last);
}




 
