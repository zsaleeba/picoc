#include <stdio.h>

int main()
{
    int fred[3] = { 12, 34, 56 };
    double joe[] = { 23.4, 56.7, 89.0 };
    
    printf("%d %d %d\n", fred[0], fred[1], fred[2]);
    printf("%f %f %f\n", joe[0], joe[1], joe[2]);

    return 0;
}
