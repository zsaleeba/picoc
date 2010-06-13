#include <stdio.h>
#include <string.h>

char a[10];

strcpy(a, "hello");
printf("%s\n", a);

strncpy(a, "gosh", 2);
printf("%s\n", a);

printf("%d\n", strcmp(a, "apple"));
printf("%d\n", strcmp(a, "goere"));
printf("%d\n", strcmp(a, "zebra"));

printf("%d\n", strlen(a));

strcat(a, "!");
printf("%s\n", a);

printf("%d\n", strncmp(a, "apple", 2));
printf("%d\n", strncmp(a, "goere", 2));
printf("%d\n", strncmp(a, "goerg", 2));
printf("%d\n", strncmp(a, "zebra", 2));

printf("%s\n", index(a, 'o'));
printf("%s\n", rindex(a, 'l'));
printf("%d\n", rindex(a, 'x') == NULL);

memset(&a[1], 'r', 4);
printf("%s\n", a);

memcpy(&a[2], a, 2);
printf("%s\n", a);

printf("%d\n", memcmp(a, "apple", 4));
printf("%d\n", memcmp(a, "grgr", 4));
printf("%d\n", memcmp(a, "zebra", 4));

