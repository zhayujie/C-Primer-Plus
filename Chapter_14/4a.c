#include <stdio.h>
#define SSN 20
#define LEN 10

struct names {
    char last_name[LEN];
    char mid_name[LEN];
    char fir_name[LEN];
};

struct person {
    char number[SSN];
    struct names name;
};

void print_info(struct person info[], int n);

int main(void)
{
    struct person info[5] = {
        {"B51414029", {"Jie", "Yu", "Zha"}},
        {"B51414010", {"Xiang", "Xiang", "Pan"}},
        {"B51414025", {"Jie", "Wen", "Jiang"}},
        {"B51414031", {"Ming", "Cheng", "Liu"}},
        {"B51414044", {"Qiang", " ", "Sha"}}
    };

    print_info(info, 5);

    return 0;
}

void print_info(struct person info[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%s, %s %c%c -- %s", info[i].name.last_name,
        info[i].name.fir_name, info[i].name.mid_name[0],
        (info[i].name.mid_name[0] == ' ') ? ' ': '.', info[i].number);
        printf("\n");
    }
}
