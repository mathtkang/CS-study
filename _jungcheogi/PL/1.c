#include <stdio.h>

void main()
{
    int a = 5;
    int s = 0;

    switch (a / 2)
    {
    case 2:
        s++;
    case 3:
        a += s;
    default:
        a++;
    }

    printf("%d %d", s, a);
}

// break가 없으니까 모든 case, default 실행됨!
// >>> 1 7