#include <stdio.h>
#define SIZE 4
void print_ar(double ar[], int n);		//打印数组元素的函数
//将两个数组相加放入第三个数组的函数
void add_ar(double ar1[], double ar2[], double ar3[], int n);
int main(void)
{
    double ar1[SIZE] = {2, 4, 5, 8};
    double ar2[SIZE] = {1, 0, 4, 6};
    double ar3[SIZE];
    
    printf("The first array:  ");
    print_ar(ar1, SIZE);
    printf("The second array: ");
    print_ar(ar2, SIZE);
    add_ar(ar1, ar2, ar3, SIZE);
    printf("The third array:  ");
    print_ar(ar3, SIZE);

    return 0;
}

void print_ar(double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%g ", ar[i]);
    printf("\n");
}

void add_ar(double ar1[], double ar2[], double ar3[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        ar3[i] = ar1[i] + ar2[i];
}
