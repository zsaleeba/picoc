#include <stdio.h>

int a;
char b;

a = 0;
while (a < 2)
{
    printf("%d", a++);
	break;

    b = 'A';
	while (b < 'C')
	{
		printf("%c", b++);
	}
    printf("e");
}
printf("\n");

int main()
{
    return 0;
}
