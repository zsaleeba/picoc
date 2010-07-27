#include <stdio.h>

int x = 'a';
char y = x;

char *a = "hello";

printf("%s\n", a);

int c;
c = *a;

char *b;
for (b = a; *b != 0; b++)
    printf("%c: %d\n", *b, *b);

char destarray[10];
char *dest = &destarray[0];
char *src = a;

while (*src != 0)
    *dest++ = *src++;

*dest = 0;

printf("copied string is %s\n", destarray);


void main() {}
