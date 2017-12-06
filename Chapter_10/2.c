#include <stdio.h>
#define SIZE 5
void copy_arr(double ar1[], double ar[], int n);
void copy_ptr(double * ar2, double * ar, int n);
void copy_ptrs(double * ar3, double * ar, double * end);
void print_array(double ar[], int n);				//打印数组的函数

int main(void)
{
    double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    copy_arr(target1, source, SIZE);
    copy_ptr(target2, source, SIZE);
    copy_ptrs(target3, source, source + SIZE);
    print_array(target1, SIZE);
    print_array(target2, SIZE);
    print_array(target3, SIZE);

    return 0;
}

void copy_arr(double ar1[], double ar[], int n)
{
    int index;
    for (index = 0; index < n; index++)
        ar1[index] = ar[index];
}

void copy_ptr(double * ar2, double * ar, int n)
{
    int i;
    for (i = 0; i < n; i++)
        *(ar2++) = *(ar++);
}

void copy_ptrs(double * ar3, double * ar, double * end)
{
    int i;
    for (i = 0; ar < end; i++)
        *(ar3++) = *(ar++);
}

void print_array(double ar[], int n)
{
    int index;
    for (index = 0; index < n; index++)
        printf("%g ", ar[index]);
    printf("\n");
}
