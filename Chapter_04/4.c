#include<stdio.h>
int main(void)
{
    float height;
    char name[40];
    printf("Input your height(cm) and name: ");
    scanf("%f%s",&height,name);
    height=height/100;
    printf("%s, you are %.3fm tall\n",name,height);
    return 0;
}
