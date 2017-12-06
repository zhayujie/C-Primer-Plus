#include <stdio.h>
#define ROWS 3
#define COLS 5
void change_ar(int ar[][COLS], int rows);		//变化数组的函数
void print_ar(int ar[][COLS], int rows);		//打印数组的函数
int main(void)
{
    int array[ROWS][COLS] =
    {
        {1, 2, 6, 3, 3},
        {6, 5, 2, 3, 2},
        {7, 8, 7, 3, 6}
    };
    
    printf("The original array:\n");
    print_ar(array, ROWS);
    change_ar(array, ROWS);
    printf("The present array:\n");
    print_ar(array, ROWS);

    return 0;
}

void change_ar(int ar[][COLS], int rows)
{
    int r, c;
    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            ar[r][c] *= 2;
}

void print_ar(int ar[][COLS], int rows)
{
    int r, c;
    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < COLS; c++)
            printf("%3d ", ar[r][c]);
        printf("\n");
    }
}
