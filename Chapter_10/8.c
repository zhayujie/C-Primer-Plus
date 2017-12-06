#include <stdio.h>
#define SIZE_SOU 7			//源数组元素个数
#define SIZE_TAR 3			//待拷贝元素个数
void copy_ptr(double * ar2, double * ar, int n);
int main(void)
{
    int i;

    double target[SIZE_TAR];
    double souce[SIZE_SOU] = {1.5, 3.75, 4.3, 2.6, 2.15, 3.27, 6.66};
    copy_ptr(target, souce + 2, SIZE_TAR);
    for (i = 0; i < SIZE_TAR; i++)
        printf("%g ", target[i]);
    printf("\n");

    return 0;
}

void copy_ptr(double * ar2, double * ar, int n)
{
    int i;
    for (i = 0; i < n; i++)
        *(ar2++) = *(ar++);
}

