#include <stdio.h>

void foo()
{
    printf("foo\n");
}
int main()
{
 int a,c;

 printf("\nTest 1\n");

 a = 0; c = 0;
 while (1)
 {
    printf("a=%d\n", a++);
    break;
    for (c=0;c<10;c++)
        printf("c=%d\n",c);
 }
 
 printf("\nTest 2\n");

 a = 0; c = 0;
 while (1)
 {
    printf("a=%d\n", a++);
    break;
    while (c < 3)
       printf("c=%d\n",c++);
 }

 printf("\nTest 3\n");

 a = 0; c = 0;
 for (c=0;c<10;c++)
 {
    printf("c=%d\n",c);
    foo();
    break;
    foo();
    for (a = 0; a < 2; a++)
        printf("a=%d\n",a);
 }

 printf("\nTest 4\n");

 a = 0; c = 0;
 for (c=0;c<10;c++)
 {
    printf("c=%d\n",c);
    foo();
    continue;
    for (a = 0; a < 2; a++)
        printf("a=%d\n",a);
    printf("bar\n");
 }

 return 0;
}
