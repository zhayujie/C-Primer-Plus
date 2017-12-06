#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 10
#define SIZE 80
char * s_gets(char * st, int n);			//获取字符串输入
char get_choice(void);						//获取选择
void print_sour(char * st[], int n);		//打印源字符串
void print_ascii(char * st[], int n);		//按ASCII码顺序打印
void print_length(char * st[], int n);		//按长度顺序打印
void print_first_word(char * st[], int n);	//按第一个单词的长度顺序打印
int first_word(char * st);					//计算第一个单词数

int main(void)
{
    char str[LIM][SIZE];
    char * ptr[LIM];
    int row = 0;							//输入的字符串数量
    char choice;							//用户输入的选择字符

    printf("Input some strings before EOF (no more than 10):\n");
    while (row < LIM && s_gets(str[row], SIZE) != NULL)
    {
        ptr[row] = str[row];				//设置指针指向字符串
        row++;
    }
    while((choice = get_choice()) != 'q')
    {
        printf("\n");
        switch (choice)
        {
            case 'a': print_sour(ptr, row);
                      break;
            case 'b': print_ascii(ptr, row);
                      break;
            case 'c': print_length(ptr, row);
                      break;
            case 'd': print_first_word(ptr, row);
                      break;
            default: printf("Error!\n");
                     break;
        }
        printf("\n");
    }
    printf("Bye.\n");
    
    return 0;
}

//获取用户选择
char get_choice(void)
{
    char ch;
    
    printf("a. print the sourse strings.     b. print in order of ASCII.\n");
    printf("c. print in order of length.	 d. print in order of the first word's length.\n");
    printf("q. quit.\n");
    printf("Enter a character (a, b, c, d or q):");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    while (ch < 'a' || ch > 'd' && ch != 'q')
    {
        printf("Please input the right option (a, b, c, d or q): ");
        ch = getchar();
        while (getchar() != '\n')
        continue;
    }
    return ch;
}
    
//打印源字符串
void print_sour(char * st[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        puts(st[i]);
}
    
//按ASCII中的顺序打印字符串
void print_ascii(char * st[], int n)
{
    int i, j;
    char * temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (strcmp(st[i], st[j]) > 0)
            {
                temp = st[j];
                st[j] = st[i];
                st[i] = temp;
            }
    for (i = 0; i < n; i++)
        puts(st[i]);
}

//按长度顺序打印
void print_length(char * st[], int n)
{
    int i, j;
    char * temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (strlen(st[i]) > strlen(st[j]))
                {
                    temp = st[j];
                    st[j] = st[i];
                    st[i] = temp;
                }
    for (i = 0; i < n; i++)
        puts(st[i]);
}
//按第一个单词的长度顺序打印
void print_first_word(char * st[], int n)
{
    int i, j;
    char * temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (first_word(st[i]) > first_word(st[j]))
                {
                    temp = st[j];
                    st[j] = st[i];
                    st[i] = temp;
                }
    for (i = 0; i < n; i++)
    puts(st[i]);
}

//计算第一个单词的长度
int first_word(char * st)
{
    int i = 0;
    int count = 0;

    while (!isalpha(st[i]))
            i++;
    while (isalpha(st[i]))
    {
        i++;
        count++;
    }

    return count;
}
    
//自定义的输入函数
char * s_gets(char * st, int n)
{
    int i = 0;
    if (fgets(st, n, stdin) != NULL)	//即返回值st不等于NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
        return st;
    }
    else
        return NULL;
}
