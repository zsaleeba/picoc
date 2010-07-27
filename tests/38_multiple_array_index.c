#include <stdio.h>

int a[4][4];
int b = 0;
int x;
int y;

for (x = 0; x < 4; x++)
{
    for (y = 0; y < 4; y++)
    {
        b++;
        a[x][y] = b;
    }
}



for (x = 0; x < 4; x++)
{
    printf("x=%d: ", x);
    for (y = 0; y < 4; y++)
    {
        printf("%d ", a[x][y]);
    }
    printf("\n");
}

void main() {}
