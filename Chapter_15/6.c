#include <stdio.h>
#include <string.h>

struct word {
    unsigned int font: 8;
    unsigned int size: 7;
    unsigned int alignment: 2;
    unsigned int bold: 1;
    unsigned int italic: 1;
};

const char * align[3] = {"left", "center", "right"};
const char * open[2] = {"off", "on"};

char get_choice(void);
char get_select(void);
void print(struct word *);

int main(void)
{
    struct word type = {1, 12, 0, 0, 0};
    char choice;
    char ch;
    int num;

    print(&type);
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
        case 'f': printf("Enter font ID (0 - 256): ");
                  scanf("%u", &num);
                  getchar();
                  type.font = num;
                  break;
        case 's': printf("Enter font ID (0 - 127): ");
                  scanf("%u", &num);
                  getchar();
                  type.size = num;
                  break;
        case 'a': printf("Select alignment:\n");
                  printf("l)left   c)center   r)right\n");
                  if ((ch = get_select()) == 'l')
                      type.alignment = 0;
                  else if (ch == 'c')
                      type.alignment = 1;
                  else
                      type.alignment = 2;
                  break;
        case 'b': type.bold = !type.bold;
                  break;
        case 'i': type.italic = !type.italic;
                  break;
        default : break;
        }
        print(&type);
    }
    printf("Bye.\n");

    return 0;
}

char get_choice(void)
{
    char ch;
    
    printf("f)change font\ts)change size\ta)change alignment\n");
    printf("b)toggle bold\ti)toggle italic\nq)quit\n");

    while (strchr("fsabiq", ch = getchar()) == NULL)
    {
        while (getchar() != '\n')
            continue;
        printf("Please input the right letter.\n");
    }
    while (getchar() != '\n')
        continue;
    
    return ch;
}

char get_select(void)
{
    char ch;

    while (strchr("lcr", ch = getchar()) == NULL)
    {
        while (getchar() != '\n')
            continue;
        printf("Please input the right letter.\n");
    }
    while (getchar() != '\n')
        continue;
    
    return ch;
}

void print(struct word * pst)
{
    printf("\n ID  SIZE  ALIGNMENT   B    I\n");
    printf("%3u", pst->font);
    printf("%5u", pst->size);
    printf("%10s", align[pst->alignment]);
    printf("%7s", open[pst->bold]);
    printf("%5s\n\n", open[pst->italic]);
}
