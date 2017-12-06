#include<stdio.h>
#define SIZE 26
int main(void)
{
    
    char ch[SIZE];
    int index;
    
    for(index=0;index<SIZE;index++)
    {
        ch[index]='a'+index;
        printf("%c ",ch[index]);
    }
    printf("\n");
    return 0;
}
        
    

        
