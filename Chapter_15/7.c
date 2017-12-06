#include <stdio.h>
#include <string.h>

#define ID_MASK 0xff
//括号缺失会出错
#define SIZE_MASK (0x7f << 8)
#define ALIGN_MASK (0x3 << 15)

#define CENTER (0x1 << 15)
#define RIGHT (0x2 << 15)
#define BOLD (0x1 << 17)
#define ITALIC (0x1 << 18)

const char * align[3] = {"left", "center", "right"};
const char * open[2] = {"off", "on"};

char get_choice(void);
char get_select(void);
void print(unsigned long);

int main(void)
{
    unsigned long type = 0;
    char choice;
    char ch;
    int num;

    print(type);
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
        case 'f': printf("Enter font ID (0 - 256): ");
                  scanf("%lu", &num);
                  getchar();
                  type &= ~ID_MASK;		//把表示字体ID的位清空
                  type |= num;			//重置字体ID
                  break;
        case 's': printf("Enter font ID (0 - 127): ");
                  scanf("%lu", &num);
                  getchar();
                  type &= ~SIZE_MASK;
                  type |= (num << 8);
                  break;
        case 'a': type &= ~ALIGN_MASK;
                  printf("Select alignment:\n");
                  printf("l)left   c)center   r)right\n");
                  if ((ch = get_select()) == 'c')
                      type |= CENTER;
                  else if (ch == 'r')
                      type |= RIGHT;
                      break;
        case 'b': type ^= BOLD;
                  break;
        case 'i': type ^= ITALIC;
                  break;
        default : break;
        }
        print(type);
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

void print(unsigned long num)
{
    printf("\n ID  SIZE  ALIGNMENT   B    I\n");
    printf("%3u", num & ID_MASK);
    printf("%5u", (num & SIZE_MASK) >> 8);
    printf("%10s", align[(num & ALIGN_MASK) >> 15]);
    printf("%7s", open[(num & BOLD) >> 17]);
    printf("%5s\n\n", open[(num & ITALIC) >> 18]);
}
