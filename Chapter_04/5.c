#include<stdio.h>
int main(void)
{
    float speed,size,time;
    printf("Input the download speed(Mb/s) and the file size(MB):\n");
    scanf("%f%f",&speed,&size);
    time=size/speed*8.0;
    printf("At %.2f megabits per second, a file of %.2f megabytes\n",speed,size);
    printf("downloads in %.2f seconds.\n",time);
    return 0;
}

