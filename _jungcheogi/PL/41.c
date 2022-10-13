#include <stdio.h>

void main()
{
    int a = 3, b = 4;
    int ret = 0;

    ret = a > b ? a : b;

    switch (ret)
    {
    case 0:
        printf("A");
    case 4:
        printf("B");
    case 3:
        printf("C");
    case 7:
        printf("D");
    default:
        printf("E");
    }
}