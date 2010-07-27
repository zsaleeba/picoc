#include <stdio.h>

int a;
int p;
int t;

a = 1;
p = 0;
t = 0;

while (a < 100)
{
    printf("%d\n", a);
    t = a;
    a = t + p;
    p = t;
}

void main() {}
