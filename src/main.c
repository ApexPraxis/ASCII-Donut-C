#include <stdio.h>

int main(void)
{
    int x = 2;
    int y = 1;
    char screen[5][10];

    // Fill the screen with dots
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            screen[row][col] = '.';
        }
    }

    int screenX = x + 2;
    int screenY = y + 1;

    screen[screenY][screenX] = '*';

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