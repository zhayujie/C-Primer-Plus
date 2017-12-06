#include <stdio.h>
#define LOW 1			//初始下限
#define HIGH 100		//初始上限
int get_guess(void);
int main(void)
{
    char response;
    int guess;
    int low = LOW;
    int high = HIGH;

    guess = (low + high) / 2;
    printf("Pick an integer from %d to %d. I will try to guess ",
            LOW, HIGH);
    printf("it.\nRespond with a y if my guess is right, with an s if it\n");
    printf("is small and with a b if it is big.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((response = getchar()) != 'y')
    {
        if (response == 's')
        {
            low = guess;
            guess = (guess + high) / 2;
        }
        else if (response == 'b')
        {
            high = guess;
            guess = (guess + low) / 2;
        }
        else
            printf("Sorry, I understand only y, s and b.\n");
        
        printf("Well, then, is it %d?\n", guess);
        //跳过剩余输入行
        while (getchar() != '\n')
            continue;
        //使取值能到达上限
        if (guess == HIGH - 1)
            guess++;
    }
    printf("I knew i could do it!\n");
    
    return 0;
}
