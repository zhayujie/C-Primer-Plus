#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
#define LEN 20
#define MAX 12
#define MAXFL 5

struct seat {
    int num;
    int isassign;
    char fname[LEN];
    char lname[LEN];
};

void read_file(struct seat * ps);		//从文件读取
void initialize(struct seat * ps);		//初始化结构
char get_flight(void);				//用户选择航班
char get_choice(void);					//用户输入选择
void show_number(struct seat * ps);		//空位置的个数
void show_empty(struct seat * ps);		//打印所有空位置
void show_list(struct seat * ps);		//打印所有位置信息
void assign_seat(struct seat * ps);		//预订一个位置
void delete_seat(struct seat * ps);		//删除一个位置
void write_file(struct seat * ps);		//数据写入文件
char * s_gets(char * st, int n);		//输入字符串
void is_confirmed(void);				//确认座位分配

//全局变量，值为1时表示被确认，值为0时未确认
int isconf;
char flight_num[MAXFL];

int main(void)
{
    char ch, flight;
    struct seat customer[MAX];
    
    initialize(customer);
    read_file(customer);
    
    //用户输入选项
    while ((flight = get_flight()) != 'q')
    {
        isconf = 0;
        while ((ch = get_choice()) != 'g')
        {
            switch (ch)
            {
                case 'a': show_number(customer);
                          break;
                case 'b': show_empty(customer);
                          break;
                case 'c': show_list(customer);
                          break;
                case 'd': assign_seat(customer);
                          break;
                case 'e': delete_seat(customer);
                          break;
                case 'f': is_confirmed();
                          break;
                default: printf("Program error.\n");
                        break;
            }
        }
    //将数据输出至文件中
    if (isconf)
        write_file(customer);
    }
    
    
    return 0;
}
    
void initialize(struct seat * ps)
{
    int i;

    for (i = 0; i < MAX; i++)
    {
        ps[i].num = i + 1;
        ps[i].isassign = 0;
        strcpy(ps[i].fname, "");
        strcpy(ps[i].lname, "");
    }
}

void read_file(struct seat * ps)
{
    FILE * fp;
    
    
    if((fp = fopen("seat.txt", "a+b")) == NULL)
    {
        fprintf(stderr, "Can't open seat.txt.\n");
        exit(EXIT_FAILURE);
    }
    fread(ps, sizeof(struct seat), MAX, fp);
}

char get_flight(void)
{
    char ch;

    printf("To choose a flight, enter its letter labal:\n");
    printf("a). 102             b). 311\n");
    printf("c). 444             d). 519\n");
    printf("q). quit.\n");
    while ((ch = getchar()) < 'a' || ch > 'd' && ch != 'q')
    {
        while (getchar() != '\n')
            continue;
        printf("Please input the right letter (a, b, c, d or q).\n");
    }
    while (getchar() != '\n')
        continue;
    if (ch == 'a')
        strcpy(flight_num, "102");
    else if (ch == 'b')
        strcpy(flight_num, "311");
    else if (ch == 'c')
        strcpy(flight_num, "444");
    else if (ch == 'd')
        strcpy(flight_num, "519");

    return ch;
}

char get_choice(void)
{
    char ch;
    
    printf("The number of the flight is %s. To choose a function, "
        "enter its letter label:\n", flight_num);
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Confirmed the seat assignment\n");
    printf("g) Quit\n");

    while ((ch = getchar()) < 'a' || ch > 'g')
    {
        while (getchar() != '\n')
            continue;
        printf("Please input the right letter.\n");
    }
    while (getchar() != '\n')
            continue;

    return ch;
}

void show_number(struct seat * ps)
{
    int i;
    int count = 0;

    for(i = 0; i < MAX; i++)
    {
        if (ps[i].isassign == 0)
            count++;
    }
    printf("The number of empty seats is %d\n", count);
}

void show_empty(struct seat * ps)
{
    int i;

    printf("The list of empty seats in %s flight:\n", flight_num);
    for (i = 0; i <	MAX; i++)
    {
        if (!ps[i].isassign)
            printf("%d ", ps[i].num);
    }
    printf("\n");
}

void show_list(struct seat * ps)
{
    int i;

    printf("The list of seats in %s flight:\n", flight_num);
    for (i = 0; i <	MAX; i++)
    {
        printf("%d %s %s\n", ps[i].num, ps[i].fname, ps[i].lname);
    }
    printf("The seat assignment is not confirmed.\n");
}

void assign_seat(struct seat * ps)
{
    int number;
    int ret_val;

    printf("Please input the number of seat you want to book (1 to 12) "
        "in %s flight:\n", flight_num);
    while ((ret_val = scanf("%d", &number)) != 1|| number < 1 || number > 12 ||
        ps[number - 1].isassign == 1)
    {
        if (ret_val != 1 || number < 1 || number > 12)
            printf("Sorry, please input a integer from 1 to 12.\n");
        else
            printf("Sorry, the seat is assigned, please reselect:\n");
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        continue;
    printf("Now, input your firstname:\n");
    s_gets(ps[number - 1].fname, LEN);
    printf("Input your lastname:\n");
    s_gets(ps[number - 1].lname, LEN);
    ps[number - 1].isassign = 1;
    printf("OK.\n");
}


void delete_seat(struct seat * ps)
{
    int number;

    printf("Please input the number of seat you want to delete (1 to 12) "
        "in %s flight:\n", flight_num);
    while (scanf("%d", &number) != 1 || number < 1 || number > 12 ||
        ps[number - 1].isassign == 0)
    {
        if (ps[number - 1].isassign == 1)
            printf("Sorry, the seat is empty, please reselect:\n");
        else
            printf("Sorry, please input a integer from 1 to 12.\n");
        while (getchar() != '\n')
            continue;
    }
    getchar();
    strcpy(ps[number - 1].fname, "");
    strcpy(ps[number - 1].lname, "");
    ps[number - 1].isassign = 0;
    printf("OK.\n");
}

void is_confirmed(void)
{
    isconf = 1;
    printf("The seat assignment is confirmed.\n");
}

void write_file(struct seat * ps)
{
    FILE * fp;

    fp = fopen("seat.txt", "w+b");
    fwrite(ps, sizeof(struct seat), MAX, fp);
    fclose(fp);
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
