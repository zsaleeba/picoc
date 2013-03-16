#include "stdio.h"

#define MIN(a,b) ((a) < (b) ? (a) : (b))

void main()
{
    float x = MIN(1,2);
    int y = 14;
    float z;
    z = MIN(y, 13.5);
    y = MIN(y, 13);
    
    float pi = 3.14;
    int pi_int = pi;
    
    printf("Macro test: %d %d %f %d \n", x, y, z, pi_int);
}
