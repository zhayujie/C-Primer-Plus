#include <stdio.h>
int main(void)
{
    int num;
    int n_even = 0, n_odd = 0;		//偶数和奇数个数
    int sum_even = 0, sum_odd = 0;	//偶数和奇数和

    printf("Enter some integers(0 to quit):\n");
    scanf("%d", &num);
    while (num != 0)
    {
        if (num % 2 == 0)
        {
            n_even++;
            sum_even += num;
        }							//计算偶数个数和偶数和
        else
        {
            n_odd++;
            sum_odd +=num;
        }							//计算奇数个数和奇数和
        scanf("%d",&num);
    }
    printf("The number of even numbers is %d, "
            "and the everage of even numbers is %.2f\n",
            n_even, (n_even == 0) ? 0 : (float)sum_even / n_even);
    printf("The number of odd numbers is %d, "
            "and the everrage of odd numers is %.2f\n",
            n_odd, (n_odd == 0) ? 0 : (float)sum_odd / n_odd);

    return 0;
}
