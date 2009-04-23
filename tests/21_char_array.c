char *a = "hello";

printf("%s\n", a);

int c;
c = *a;

char *b;
for (b = a; *b != 0; b++)
    printf("%c: %d\n", *b, *b);

char destarray[10];
char *dest;
char *src;

dest = &destarray[0];
src = a;
while (*src != 0)
    *dest++ = *src++;

*dest = 0;

printf("copied string is %s\n", destarray);

