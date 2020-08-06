#include<stdio.h>
void main()
{
    struct X{
        short a[3];//6+2
        long b;//4
    };//12
    struct Z{
        char c;//1+1
        short dd;//2
        char ddd;//1+3
        struct X d;//12+4
        double e;//8
    };//32
    union A{
        struct Z a;
        char g[32];
    };
    struct X d={{1,2,3},4};
    struct Z a={
        'a',5,'b', d, 6.7
    };
    union A h={a};
    printf("%c",h.g[0]);
}