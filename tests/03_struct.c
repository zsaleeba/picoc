#include <stdio.h>

struct fred
{
    int boris;
    int natasha;
};

struct fred bloggs;

bloggs.boris = 12;
bloggs.natasha = 34;

printf("%d\n", bloggs.boris);
printf("%d\n", bloggs.natasha);
