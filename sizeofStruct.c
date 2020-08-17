#include <stdio.h>
void main()
{
    struct learn
    {
        char a;
        short b;
        long c;
        double d;
    } AA;
    struct learn
    {
        unsigned int a:8;
        unsigned short b:8;
        long c;
        double d;
    } BB;
    size_t e = sizeof(AA.d);
    //sizeof的操作数不能是位域
    size_t f = sizeof(BB.a);
    printf("%u", e);
}