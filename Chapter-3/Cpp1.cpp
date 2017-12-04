#include<stdio.h>
int main(void)
{
	double quarts,n;
	double m=3.0e-23;

	printf("input the number of quarts: ");
	scanf("%lf",&quarts);
    n=quarts*950/m;
	printf("the numble of H2O molecules is: %e\n",n);

	return 0;

}