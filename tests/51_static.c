#include <stdio.h>

static int fred = 1234;
static int joe;

void henry()
{
    static int fred = 4567;

    printf("%d\n", fred);
    fred++;
}

void main()
{
    printf("%d\n", fred);
    henry();
    henry();
    henry();
    henry();
    printf("%d\n", fred);
    fred = 8901;
    joe = 2345;
    printf("%d\n", fred);
    printf("%d\n", joe);
}
