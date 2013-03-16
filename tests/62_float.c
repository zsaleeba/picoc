#include <stdio.h>

void main()
{
    double x = 3.14;
    double y = 1e-3;
    double z = 1e-13;
    double q = 4.0f / 3.0f;
    printf("%f %f %f %f\n", x, y, z * 1e15, q);
}
