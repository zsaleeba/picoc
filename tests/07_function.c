#include <stdio.h>

int myfunc(int x)
{
    return x * x;
}

printf("%d\n", myfunc(3));
printf("%d\n", myfunc(4));

void vfunc(int a)
{
    printf("a=%d\n", a);
}

vfunc(1234);

void qfunc()
{
    printf("qfunc()\n");
}

qfunc();

void main() {}
