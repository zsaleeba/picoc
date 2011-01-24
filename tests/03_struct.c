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

//struct fred jones[2];
//jones[0].boris = 12;
//jones[0].natasha = 34;

void main() {}
