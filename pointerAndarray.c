#include <stdio.h>
void main()
{
    int a[10] = {1,
                 3,
                 5,
                 7};
    int b[2][2] = {{1, 3}, {5, 7}};
    char c[2][3] = {{1, 3, 5}, {7, 9, 11}};
    int *p = a;
    int *q = b;
    printf("%d,%d\n", *(p++), *(a + 1));
    printf("%d,%d\n", **(b + 1), **b);
    printf("%d,%d,%d\n", sizeof(b), sizeof(b + 1), sizeof(*(b + 1)));
    printf("%d,%d,%d\n", sizeof(b), sizeof(&b[1]), sizeof(b[1]));
    printf("%d,%d,%d\n", sizeof(*b), sizeof(**b), sizeof(**(b + 1)));
    printf("%d,%d,%d\n", *q, *(q + 1), *(q + 2));
}