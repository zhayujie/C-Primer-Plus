#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 80
#define LIM 10
int main(int argc, char * argv[])
{
    int col;
    int i;
    int row = 0;
    char str[LIM][SIZE];
    
    while (row < LIM && fgets(str[row], SIZE, stdin) != NULL)
    {
        if (argc == 1);
        else if (!strcmp(argv[1], "-p"));
        else if (!strcmp(argv[1], "-u"))
            for (col = 0; str[row][col] != '\0'; col++)
                str[row][col] = toupper(str[row][col]);
        else if (!strcmp(argv[1], "-l"))
            for (col = 0; str[row][col] != '\0'; col++)
                str[row][col] = tolower(str[row][col]);
        row++;
    }
    for (i = 0; i < row; i++)
        fputs(str[i], stdout);

    return 0;
}


