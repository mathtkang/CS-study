#include <stdio.h>

int num(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void main()
{
    printf("%d", num(10, 20) + num(30, 20));
}