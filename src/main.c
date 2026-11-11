
#include <stdio.h>
#include <math.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

int main(void)
{
    
    char screen[HEIGHT][WIDTH];
    float zbuffer[HEIGHT][WIDTH];
    float K1 = 30.0;
float K2 = 5.0;

float x = 2.0;
float y = 1.0;
float z = 2.0;

int screenX = (int)(K1 * x / (K2 + z) + WIDTH / 2);
int screenY = (int)(K1 * y / (K2 + z) + HEIGHT / 2);

if (screenX >= 0 && screenX < WIDTH &&
    screenY >= 0 && screenY < HEIGHT)
{
    screen[screenY][screenX] = '*';
}

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
