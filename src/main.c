
#include <stdio.h>
#include <math.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

int main(void)
{
    char screen[HEIGHT][WIDTH];
    float zbuffer[HEIGHT][WIDTH];

    // Initialize both buffers
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            screen[y][x] = ' ';
            zbuffer[y][x] = 0.0;
        }
    }

    // Test the screen
    screen[HEIGHT / 2][WIDTH / 2] = '*';

    // Print the screen
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c", screen[y][x]);
        }

        printf("\n");
    }

    return 0;
}
