
#include <stdio.h>
#include <math.h>

int main(void)
{
    double radius = 5.0;

    for (double angle = 0.0; angle < 2 * M_PI; angle += 0.1)
    {
        double x = radius * cos(angle);
        double y = radius * sin(angle);

        printf("x = %7.3f | y = %7.3f\n", x, y);
    }

    return 0;
}
