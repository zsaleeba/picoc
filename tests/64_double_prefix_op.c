// credits: CSmith, a random generator of C programs.

#include "stdio.h"

void func_1(void)
{
    int x = 5;
    int* px = &x;
    int** ppx = &px;
    int*** pppx = &ppx;
    int a = - - x;
    printf("a=%d\n", a);
    int b = - - - x;
    printf("b=%d\n", b);
    int c = -***pppx;
    printf("c=%d\n", c);
    int d = - -****&pppx;
    printf("d=%d\n", d);
}

void main()
{
    func_1();
}
