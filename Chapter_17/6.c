#include <stdio.h>
#define SIZE 8

int find(int ar[], int size, int n);

int main(void)
{
    int n;
    int array[SIZE] = {1, 3, 6, 7, 9, 10, 13, 15};

    printf("Please input the integer you want to search:\n");
    while (scanf("%d", &n) == 1)
    {
        if (find(array, SIZE, n))
            printf("Find.\n");
        else
            printf("Can't find.\n");
        printf("Your next input (q to quit):\n");
    }

    return 0;
}

int find(int * ar, int size, int n)
{
    int head = 0;
    int end = size - 1;
    int mid;
    
    while (head <= end)
    {
        mid = (head + end) / 2;
        if (n < ar[mid])
            end = mid - 1;
        else if (n > ar[mid])
            head = mid + 1;
        else
            return 1;
    }

    return 0;
}






