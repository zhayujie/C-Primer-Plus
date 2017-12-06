#include<stdio.h>
#include<string.h>
int main(void)
{
    char firstname[40],lastname[40];
    printf("Input your firstname: ");
    scanf("%s",firstname);
    printf("Input your lastname: ");
    scanf("%s",lastname);
    printf("%s %s\n",firstname,lastname);
    printf("%*d %*d\n",
    strlen(firstname),strlen(firstname),strlen(lastname),strlen(lastname));
    printf("%s %s\n",firstname,lastname);
    printf("%*d %*d\n",
    -strlen(firstname),strlen(firstname),-strlen(lastname),strlen(lastname));
    return 0;
}


