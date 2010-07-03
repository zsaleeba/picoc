#include <stdio.h>

int main(int argc, char **argv)
{
    int Count;

    printf("hello world %d\n", argc);
    for (Count = 0; Count < argc; Count++)
        printf("arg %d: %s\n", Count, argv[Count]);

    return 0;
}
