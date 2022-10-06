#include <stdio.h>

void main()
{
    int a = 5;
    int b = 7;

    printf("%d\n", a++ + ++b);
    printf("%d %d\n", ++a, ++b);
}