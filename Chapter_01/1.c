#include <stdio.h>
int main(void) {
    double inch, cm;
    
    printf("Please input the inches: ");
    scanf("%lf", &inch);
    cm = inch * 2.54;
    printf("%g cm\n", cm);
    
    return 0;
}