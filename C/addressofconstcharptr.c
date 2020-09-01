#include <stdio.h>
#include <string.h>

void main()
{
    const char *buf1 = "hello";
    const char *buf2 = "hello";
    if (buf1 == buf2)
    {
        printf("equal\n");
        printf("%p\n", buf1);
    }
    if (strcmp(buf1, buf2) == 0)
    {
        printf("equal\n");
        printf("%p\n", buf2);
    }
}