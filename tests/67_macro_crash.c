#include <stdio.h>

void printArray(void) {
#define SIZE 10
    int array[SIZE] = {5, 4, 3, 9, 1, 8, 6, 7, 5, 2};
    printf("4: %d\n", array[4]);
}

void main()
{
    printArray();
}
