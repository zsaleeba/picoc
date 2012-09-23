#include <stdio.h>

struct s1;

struct s2
{
    struct s1 *s;
};

struct s1
{
    struct s2 *s;
};

void main()
{
    printf("ok\n");
}
