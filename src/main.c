#include <stdio.h>
#include <math.h>

#define WIDTH 40
#define HEIGHT 20

int main(void)
{
    double radius = 5.0;
    char screen[HEIGHT][WIDTH];

    // Fill the screen with empty spaces
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            screen[row][col] = ' ';
        }
    }

    // Generate circle points
    for (double angle = 0.0; angle < 2 * M_PI; angle += 0.1)
    {
        double x = radius * cos(angle);
        double y = radius * sin(angle);

        int column = WIDTH / 2 + (int)(x * 3);
        int row = HEIGHT / 2 - (int)(y * 1.5);

        screen[row][column] = '*';
    }

    // Print the screen
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            printf("%c", screen[row][col]);
        }

        printf("\n");
    }

    return 0;
}