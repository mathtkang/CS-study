#include <stdio.h>

void main()
{
    int i = 1;

    for (; i < 10;)
    {
        switch (i % 2)
        {
        case 0:
            printf("짝수: %d\n", i);
            break;
        default:
            printf("홀수: %d\n", i);
        }
        i += 3;
    }
}
