#include <stdio.h>
#include <math.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define PI 3.14159265f

int main(void)
{
    char screen[HEIGHT][WIDTH];
    float zbuffer[HEIGHT][WIDTH];

    float R = 2.0f;
    float r = 1.0f;
    float A = 0.8f;
    float B = 0.8f;

    float K1 = 36.0f;
    float K2 = 8.0f;

    const char shades[] = " .:-=+*#%@";

    float lx = -0.4f;
    float ly = 0.6f;
    float lz = -0.7f;

    // Clear terminal once before animation starts
    printf("\033[2J");
    fflush(stdout);

    while (1)
    {
        // Reset screen and depth buffer
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                screen[y][x] = ' ';
                zbuffer[y][x] = 0.0f;
            }
        }

        // Generate donut
        for (float theta = 0; theta < 2 * PI; theta += 0.04f)
        {
            for (float phi = 0; phi < 2 * PI; phi += 0.04f)
            {
                float ct = cosf(theta);
                float st = sinf(theta);
                float cp = cosf(phi);
                float sp = sinf(phi);

                float x = (R + r * cp) * ct;
                float y = (R + r * cp) * st;
                float z = r * sp;

                // Rotate around Y axis
                float x1 = x * cosf(B) + z * sinf(B);
                float z1 = -x * sinf(B) + z * cosf(B);

                // Rotate around X axis
                float y1 = y * cosf(A) - z1 * sinf(A);
                float z2 = y * sinf(A) + z1 * cosf(A);

                // Perspective projection
                float depth = K2 + z2;

                if (depth <= 0.0f)
                    continue;

                float invDepth = 1.0f / depth;

                int screenX = (int)(WIDTH / 2 + K1 * x1 * invDepth);
                int screenY = (int)(HEIGHT / 2 - K1 * 0.5f * y1 * invDepth);

                // Rotate surface normal
                float nx = cp * ct;
                float ny = cp * st;
                float nz = sp;

                float nx1 = nx * cosf(B) + nz * sinf(B);
                float nz1 = -nx * sinf(B) + nz * cosf(B);

                float ny1 = ny * cosf(A) - nz1 * sinf(A);
                float nz2 = ny * sinf(A) + nz1 * cosf(A);

                // Calculate lighting
                float brightness = nx1 * lx + ny1 * ly + nz2 * lz;

                if (brightness < 0.0f)
                    brightness = 0.0f;

                if (brightness > 1.0f)
                    brightness = 1.0f;

                // Depth testing and shading
                if (screenX >= 0 && screenX < WIDTH &&
                    screenY >= 0 && screenY < HEIGHT)
                {
                    if (invDepth > zbuffer[screenY][screenX])
                    {
                        zbuffer[screenY][screenX] = invDepth;

                        int shade = (int)(brightness * (sizeof(shades) - 2));

                        screen[screenY][screenX] = shades[shade];
                    }
                }
            }
        }

        // Move cursor to top-left without clearing every frame
        printf("\033[H");

        // Print frame
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                printf("%c", screen[y][x]);
            }

            printf("\n");
        }

        fflush(stdout);

        // Update rotation
      A += 0.08f;
B += 0.04f;

        // Small delay
        clock_t start = clock();

        while ((double)(clock() - start) / CLOCKS_PER_SEC < 0.02)
        {
        }
    }

    return 0;
}
