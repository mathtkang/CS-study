#include <stdio.h>

void main()
{
    int a = 4;
    int r = 3 > 5 ? ++a : --a;
    // int r = --a
    // 선감소 후대입 (따라서 r은 3)

    printf("%d", r);
}
