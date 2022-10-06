#include <stdio.h>

void main()
{
    int a = 2;
    int b = 5;
    int c = 3;

    b /= a;
    c %= a;

    printf("%d %d", b, c);
}