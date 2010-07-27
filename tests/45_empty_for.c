#include <stdio.h>

int main()
{
    int Count = 0;
    
    for (;;)
    {
        Count++;
        printf("%d\n", Count);
        if (Count >= 10)
            break;
    }
    
    return 0;
}
