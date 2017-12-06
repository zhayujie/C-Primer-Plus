#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void roll_count(int sets, int sides, int dice);
int main(void)
{
    int sets;
    int sides, dice;
    
    srand((unsigned int)time(0));
    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &sets) == 1)
    {
        printf("How many sides and how many dice? ");
        scanf("%d%d", &sides, &dice);
        printf("Here are %d sets of %d %d-sided throws.\n",
                sets, dice, sides);
        roll_count(sets, sides, dice);
        printf("How many sets? Enter q to stop: ");
    }
    printf("Bye.\n");
}

void roll_count(int sets, int sides, int dice)
{
    int i, j;
    int roll;

    if (sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return;
    }
    if (dice < 1)
    {
        printf("Need at least 1 die.\n");
        return;
    }
    srand((unsigned int)time(0));
    for (i = 0; i < sets; i++)
    {
        roll = 0;
        for (j = 0; j < dice; j++)
            roll += rand() % sides + 1;
        printf("%d ", roll);
    }
    printf("\n");
}



        
