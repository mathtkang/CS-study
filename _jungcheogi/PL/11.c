#include <stdio.h>

void main()
{
    int i = 3, j = 4;

    printf("%d", 2 && 3);         //t && t -> t => 1
    printf("%d", i < 2 || j < 3); // f || f -> f => 0
}

// 논리연산자: 0은 false, 0이 아닌 모든 수는 true
// 1 / 0