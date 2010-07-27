#include <stdio.h>

int factorial(int i) 
{
    if (i < 2)
        return i;
    else
        return i * factorial(i - 1);
}

int Count;

for (Count = 1; Count <= 10; Count++)
    printf("%d\n", factorial(Count));

void main() {}
