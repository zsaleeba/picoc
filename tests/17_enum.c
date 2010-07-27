#include <stdio.h>

enum fred
{
    a,
    b,
    c,
    d,
    e = 54,
    f = 73,
    g,
    h
};

enum fred frod;

printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
printf("%d\n", frod);
frod = 12;
printf("%d\n", frod);
frod = e;
printf("%d\n", frod);

void main() {}
