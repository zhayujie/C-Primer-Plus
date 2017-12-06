#include <stdio.h>
#define ROWS 3
#define COLS 5
void copy_ar(double ar1[][COLS], double ar[][COLS], int n);		//拷贝数组的函数
void print_ar(double ar[][COLS], int rows);						//打印数组的函数
int main(void)
{
    double target[ROWS][COLS];
    double source[ROWS][COLS] =
    {
        {1.2, 2.3, 2.6, 3.5, 3.2},
        {4.6, 5.2, 2.8, 3.3, 2.1},
        {7.8, 8.6, 7.2, 3.9, 6.6}
    };
    
    printf("The original array:\n");
    print_ar(source, ROWS);
    copy_ar(target, source, ROWS);
    printf("The copied array:\n");
    print_ar(target, ROWS);

    return 0;
}

void copy_ar(double ar1[][COLS], double ar[][COLS], int rows)
{
    int r, c;
    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            ar1[r][c] = ar[r][c];
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
