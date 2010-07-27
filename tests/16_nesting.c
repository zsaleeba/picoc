#include <stdio.h>

int x, y, z;

for (x = 0; x < 2; x++)
{
    for (y = 0; y < 3; y++)
    {
        for (z = 0; z < 3; z++)
        {
            printf("%d %d %d\n", x, y, z);
        }
    }
}

void main() {}
