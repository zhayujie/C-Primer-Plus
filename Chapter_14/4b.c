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

void print_info(struct person info);

int main(void)
{
    int index;

    struct person info[5] = {
        {"B51414029", {"Jie", "Yu", "Zha"}},
        {"B51414010", {"Xiang", "Xiang", "Pan"}},
        {"B51414025", {"Jie", "Wen", "Jiang"}},
        {"B51414031", {"Ming", "Cheng", "Liu"}},
        {"B51414044", {"Qiang", " ", "Sha"}}
    };

    for (index = 0; index < 5; index++)
        print_info(info[index]);

    return 0;
}

void print_info(struct person info)
{
    printf("%s, %s %c%c -- %s", info.name.last_name,
    info.name.fir_name, info.name.mid_name[0],
    (info.name.mid_name[0] == ' ') ? ' ': '.', info.number);
    printf("\n");
    
}

