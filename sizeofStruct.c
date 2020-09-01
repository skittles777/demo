#include <stdio.h>
void main()
{
    struct test
    {
        char a;
        short b;
        long c;
        double d;
    } AA;
    struct learn
    {
        unsigned int a:1;
        unsigned short b:1;
        long c;
        double d;
    } BB;
    size_t e = sizeof(AA);
    //sizeof的操作数不能是位域
    size_t f = sizeof(BB);
    printf("%u\n", e);
    printf("%u\n", f);
}