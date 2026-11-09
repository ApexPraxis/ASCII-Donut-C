#include <stdio.h>

int main(void)
{
    char screen[5][10];

    // Fill the screen with dots
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            screen[row][col] = '.';
        }
    }

    // Place a star
    screen[2][4] = '*';

    // Print the screen
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            printf("%c", screen[row][col]);
        }

        printf("\n");
    }

    return 0;
}