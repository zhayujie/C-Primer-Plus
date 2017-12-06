#include<stdio.h>
#include<float.h>
int main(void)
{
    double a=1.0/3.0;
    float b=1.0/3.0;
    printf("%.6f   %.6f\n",a,b);   //左侧double型 右侧float型
    printf("%.12f,   %.12f\n",a,b);
    printf("%.16f,   %.16f\n",a,b);
    printf("DBL_DIG: %d\n",DBL_DIG);
    printf("FLT_DIG: %d\n",FLT_DIG);
    return 0;
}

