#include <stdio.h>

int fn(int k)
{
    if (k <= 2)
        return 1;
    else
        return fn(k - 1) + fn(k - 2);
}

int main()
{
    printf("%d", fn(5));
    return 0;
}
