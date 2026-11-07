#include <stdio.h>
#include <math.h>

int main(void)
{
    double R = 2.0;
    double r = 1.0;

    for (double theta = 0.0; theta < 2 * M_PI; theta += 0.1)
    {
        for (double phi = 0.0; phi < 2 * M_PI; phi += 0.1)
        {
            double x = (R + r * cos(phi)) * cos(theta);
            double y = (R + r * cos(phi)) * sin(theta);
            double z = r * sin(phi);

            printf("x = %7.3f | y = %7.3f | z = %7.3f\n", x, y, z);
        }
    }

    return 0;
}