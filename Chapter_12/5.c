#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void print_ar(int ar[], int n);			//打印数组元素的函数
int main(void)
{
    int i, j, temp;
    int digit[SIZE];
    srand((unsigned int)time(0));
    for (i = 0; i < SIZE; i++)
    {
        digit[i] = rand() % 10 + 1;
    }
    printf("The original numbers:\n");
    print_ar(digit, SIZE);
    for (j = 0; j < SIZE - 1; j++)
        for (i = j + 1; i < SIZE; i++)
            if (digit[j] < digit[i])
            {
                temp = digit[i];
                digit[i] = digit[j];
                digit[j] = temp;
            }
    printf("\nThe numbers in reverse order:\n");
    print_ar(digit, SIZE);
}

void print_ar(int ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%3d", ar[i]);
        if (i % 10 == 9)
            printf("\n");
    }
}
