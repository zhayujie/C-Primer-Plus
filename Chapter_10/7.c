#include <stdio.h>
#define ROWS 3
#define COLS 2
void copy_ar(double ar1[], double ar[], int n);		//拷贝数组的函数
void print_ar(double ar[][COLS], int rows);			//打印数组的函数
int main(void)
{
    int rows;
    double target[ROWS][COLS];
    double source[ROWS][COLS] = { {1.2, 2.3}, {4.6, 5.2}, {7.8, 8.6} };
    
    printf("The original array:\n");
    print_ar(source, ROWS);
    for (rows = 0; rows < ROWS; rows++)
        copy_ar(target[rows], source[rows], COLS);
    printf("The copied array:\n");
    print_ar(target, ROWS);

    return 0;
}

void copy_ar(double ar1[], double ar[], int n)
{
    int index;
    for (index = 0; index < n; index++)
        ar1[index] = ar[index];
}

void print_ar(double ar[][COLS], int rows)
{
    int r, c;
    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < COLS; c++)
            printf("%g ", ar[r][c]);
        printf("\n");
    }
}


