#include <stdio.h>

int a;
int b;
int *d;
int *e;
d = &a;
e = &b;
a = 12;
b = 34;
printf("%d\n", *d);
printf("%d\n", *e);
printf("%d\n", d == e);
printf("%d\n", d != e);
d = e;
printf("%d\n", d == e);
printf("%d\n", d != e);


void main() {}
