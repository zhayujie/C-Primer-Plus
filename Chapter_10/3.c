#include <stdio.h>
int max(int ar[], int n);
int main(void)
{
    int num[] = {23,2,32,66,3,5,25,7,3,20};
    
    printf("The biggest number is %d\n", max(num, 10));

    return 0;
}

int max(int ar[], int n)
{
    int i, max;

    for (i = 0, max = ar[0]; i < n; i++)
    {
        if (max < ar[i])
            max = ar[i];
    }
    return max;
}



