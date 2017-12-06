#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 10
void random(const int ar[], int size, int n);

int main(void)
{
    int ar[SIZE] = {1, 2, 3, 6, 7, 9, 10, 13, 26, 17};
    int i;
    int num;

    srand((unsigned int) time(NULL));
    printf("The original array:\n");
    for (i = 0; i < SIZE; i++)
        printf("%d ", ar[i]);
    printf("\nPlease input the number of integers (no more than 10)\n");
    printf("you want to take (q to quit):\n");
    while (scanf("%d", &num) == 1)
    {
        random(ar, SIZE, num);
        printf("Your next input (q to quit):\n");
    }
    puts("Bye.");

    return 0;
}

void random(const int ar[], int size, int n)
{
    int i;
    int count;
    int index;
    int acpy[SIZE];

    //创建一个数组副本，避免修改原始数组
    memcpy(acpy, ar, SIZE * sizeof(int));
    if (n > size)
        printf("The number is too big.\n");
    else
    {
        for (count = 0; count < n; count++)
        {
            index = rand() % size;
            printf("%d ", acpy[index]);
            for (i = index; i < size - 1; i++)
            {
                acpy[i] = acpy[i + 1];
            }
            size--;
        }
        printf("\n");
    }
}
