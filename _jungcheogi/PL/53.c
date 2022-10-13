#include <stdio.h>

void main()
{
    int i, j;

    for (i = 2; i <= 4; i++)
    {
        for (j = 5; j <= 7; j++)
        {
        }
    }
    // for문을 탈출한 시점에서 i,j의 값은? >>> 신중하게 생각!
    printf("%dx%d=%2d\n", j, i, j * i);
}
// 다시풀기
