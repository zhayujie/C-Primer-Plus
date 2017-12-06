#include <stdio.h>
#define SIZE 6
void reverse(double ar [], int n);
void print_ar(double ar[], int n);			//打印数组的函数
int main(void)
{
    double array[] = {1.5, 3.75, 4.3, 2.6, 2.15, 6.66};

    printf("The original array:\n");
    print_ar(array, SIZE);
    reverse(array, SIZE);					//使数据倒序排列
    printf("The present array:\n");
    print_ar(array, SIZE);

    return 0;
}

void reverse(double ar [], int n)
{
    int i;
    double temp;

    for (i = 0; i < n / 2; i++)
    {
        temp = ar[i];
        ar[i] = ar[n - i -1];
        ar[n - i -1] = temp;
    }
}


void print_ar(double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%g ", ar[i]);
    printf("\n");
}


