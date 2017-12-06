#include <stdio.h>
#define SIZE 8
int main()
{
    double num1[SIZE], num2[SIZE];
    int index1, index2, index;

    printf("Enter 8 numbers to the first array:\n");
    for (index1 = 0; index1 < SIZE; index1++)
        scanf("%lf", &num1[index1]);							//向第一个数组输入8个数
    num2[0] = num1[0];
    for (index1 = 1, index2 = 1; index1 < SIZE; index1++, index2++)
        num2[index2] = num2[index2-1] + num1[index1];
    //为第二个数组赋值（是第一个数组对应的元素之和）
    printf("The first array:  ");
    for (index=0; index < SIZE; index++) {
        printf("%6.2f", num1[index]);
    }															//输出第一个数组的内容
    printf("\nThe second array: ");
    for (index=0; index < SIZE; index++) {
        printf("%6.2f", num2[index]);							//输出第二个数组的内容
    }
    printf("\n");

    return 0;
}



