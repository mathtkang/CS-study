#include <stdio.h>

void main()
{
    int a = 3;
    int b = 7;

    switch (a % 2)
    {
    case 3:
        b += a;
    }
    printf("%d %d", a, b);
}

// switch 실행 안함
// >>> 3 7