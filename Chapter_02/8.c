#include<stdio.h>
void one_three(void);
void two(void);
int main(void)
{
    printf("starting now\n");
    one_three();
}

void one_three(void)
{
    printf("one\n");
    two();
    printf("three\n");
    printf("done!\n");
}
void two(void)
{
    printf("two\n");
}
