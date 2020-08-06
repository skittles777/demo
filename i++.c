#include<stdio.h>
void main()
{
    int i=3,a,b,c;
    // a=(++i);
    // b=a+(++i);
    // c=b+(++i);
    // printf("%d,%d,%d",a,b,c);
    a=(i++)+(i++)+(i++);
    // a=(++i)+(++i)+(++i);

    printf("%d",a);
}