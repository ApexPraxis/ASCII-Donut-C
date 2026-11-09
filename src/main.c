#include <stdio.h>

int main(void)
{
    double x = 2.0;
    double y = 3.0;

    int screenX = (int)(x * 10 + 40);
    int screenY = (int)(y * 5 + 12);

    printf("Original coordinates: (%.1f, %.1f)\n", x, y);
    printf("Screen coordinates: (%d, %d)\n", screenX, screenY);

    return 0;
}