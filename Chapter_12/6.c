#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
#define SIZE_N 10
#define SIZE_S 10
int main(void)
{
    int i, j;
    int count[SIZE_N];			//各随机数出现次数的数组
    
    unsigned int seed[SIZE_S] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (j = 0; j < SIZE_S; j++)
    {
        for (i = 0; i < SIZE_N; i++)
            count[i] = 0;
        srand(seed[j]);
        printf("seed = %d:\n", seed[j]);
        for (i = 0; i < SIZE; i++)
            count[rand() % 10]++;
        for (i = 0; i < SIZE_N; i++)
        {
            printf("%d:%-5d  ", i + 1, count[i]);
            if (i == 4)
                printf("\n");
        }
        printf("\n");
    }

    return 0;
}
        
