#include <stdio.h>
int main(void)
{
	char ch;
	int n_repl = 0;         //Ìæ»»´ÎÊý
	
	printf("Enter some texts(# to quit):\n");
	while ((ch = getchar()) != '#') {
		if (ch == '.')
		{
			ch = '!';
			n_repl++;
		}					//Ìæ»»¾äºÅ
		else if (ch == '!')
		{
			printf("!");
			n_repl++;
		}					//Ìæ»»¸ÐÌ¾ºÅ
		printf("%c", ch);
	}
	printf("\n%d substitutions were made.\n", n_repl);
	
	return 0;
}
