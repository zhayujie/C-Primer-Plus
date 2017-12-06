#include<stdio.h>
int main(void)
{
    char firstname[40],lastname[40];
    printf("Input your firstname: ");
    scanf("%s",firstname);
    printf("Input your lastname: ");
    scanf("%s",lastname);
    printf("Your name is %s,%s\n",firstname,lastname);

    return 0;
}
