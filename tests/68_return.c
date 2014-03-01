#include <stdio.h>

void demo_error()
{
  int value = 5;

  printf("Here's a print statement before quitting.\n");

  if(1) {
    printf("returning; there should be no further output.\n");
    return;
  }

  printf("This statement should not print, and does not.\n");

  switch(value)
  {
    case 5:
      printf("case 5: value = %d\n", value);
      break;
    case 0:
      printf("case 0: value=%d\n", value);
      break;
  }

  printf("This statement also should not and does not print.\n");

  return;
}

void main() 
{
    demo_error();
}
