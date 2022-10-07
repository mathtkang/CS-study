#include <stdio.h>

void main()
{
    int a = 3, b = 4, c = 2;
    int r1, r2, r3;

    r1 = b <= 4 || c == 2;   // true || true
    r2 = (a > 0) && (b < 5); // true && true
    r3 = !c;                 // !(true) -> false

    printf("%d", r1 + r2 + r3); // 1+1+0 = 2
    return 0;
}