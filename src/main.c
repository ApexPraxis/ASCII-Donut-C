#include <stdio.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24

int main(void)
{
    float R = 2.0;
    float r = 1.0;

    float theta, phi;

    for (theta = 0; theta < 6.28318; theta += 0.1)
    {
        for (phi = 0; phi < 6.28318; phi += 0.05)
        {
            float x = (R + r * cos(phi)) * cos(theta);
            float y = (R + r * cos(phi)) * sin(theta);
            float z = r * sin(phi);

            printf("x = %7.3f | y = %7.3f | z = %7.3f\n",
                   x, y, z);
        }
    }

    return 0;
}