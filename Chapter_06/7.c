//与题目不同 打印的是句子
#include<stdio.h>
#include<string.h>
#define SIZE 40
int main(void)
{
    int i,index=-1;
    char ch[SIZE];
    printf("Input a word: ");
    do
    {	index++;
    scanf("%c",&ch[index]);}
    while(ch[index]!='\n');
    for(i=index+1;i<=40;i++)
        ch[i]='\0';
    for(index=strlen(ch);index>=0;index--)
        printf("%c",ch[index]);
    printf("\n");
    return 0;
}
