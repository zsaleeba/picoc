#include <stdio.h>

#define FRED 12
#define BLOGGS(x) (12*(x))

printf("%d\n", FRED);
printf("%d, %d, %d\n", BLOGGS(1), BLOGGS(2), BLOGGS(3));


void main() {}
