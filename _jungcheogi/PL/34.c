#include <stdio.h>
void main()
{
    int ret = 4;

    switch (++ret)
    {
    case 5:
        ret += 2;
    case 3:
        ret++;
        break;
    case 4:
        ret++;
    default:
        ret *= 2;
    }
    printf("%d\n", ret);
}