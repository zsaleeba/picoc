#include <stdio.h>

printf("first for\n");

for (int i = 0; i < 3; i++)
{
    int j = i+1;
    printf("%d\n", i);
}

printf("second for\n");

for (int i = 0; i < 3; i++)
{
    printf("%d\n", i);
}
int j;

void foo()
{
    printf("foo: first for\n");

    for (int i = 0; i < 3; i++)
    {
        int j = i+1;
        printf("foo: %d\n", i);
    }
    
    while(1)
    {
        int i = 5;
        printf("foo: while: %d\n", i);
        if (1) break;
    }

    printf("foo: second for\n");

    for (int i = 0; i < 3; i++)
    {
        printf("foo: %d\n", i);
    }

    for (int i = 0; i < 100000; i++)
    {
        {
            int j = i + 1; // will be caught by VariableDefineButIgnoreIdentical
        }
    }

    for (int i = 0; i < 3; i++)
    {
        {
            int j = i;
            printf("foo: %d\n", j);
        }
    }
    
    float j[10];
}

foo();

void main(){}
