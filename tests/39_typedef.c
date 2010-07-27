#include <stdio.h>

typedef int MyInt;

MyInt a = 1;
printf("%d\n", a);

struct FunStruct
{
    int i;
    int j;
};

typedef struct FunStruct MyFunStruct;

MyFunStruct b;
b.i = 12;
b.j = 34;
printf("%d,%d\n", b.i, b.j);

typedef MyFunStruct *MoreFunThanEver;

MoreFunThanEver c = &b;
printf("%d,%d\n", c->i, c->j);

void main() {}
