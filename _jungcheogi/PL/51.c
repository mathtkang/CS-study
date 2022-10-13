#include <stdio.h>

void main()
{
    int x = 7;
    int y = 7;
    int a = ++x + y--;

    printf("%d\n", a);
}