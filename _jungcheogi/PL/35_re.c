#include <stdio.h>
void main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int *pa[] = {a, b};
    printf("%d", *(pa[1] + 1));
}

// 여기 다시