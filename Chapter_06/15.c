#include <stdio.h>
#include <string.h>
#define SIZE 255
int main(void)
{
    int index;
    char ch[SIZE];

    printf("Enter a line: ");
    for(index = 0, scanf("%c", &ch[0]); ch[index] != '\n';)
    {
        index++;
        scanf("%c", &ch[index]);
    }											//输入内容到字符数组中,回车时结束
    for(index += 1; index < SIZE; index++)
        ch[index] = '\0';						//将数组剩余空间补充为'\0'
    for(index = strlen(ch); index >=0; index--)
        printf("%c", ch[index]);				//倒序输出内容
    printf("\n");

    return 0;
}

