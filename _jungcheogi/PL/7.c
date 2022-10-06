#include <stdio.h>

void main()
{
    int x = 1;
    int y = 2;
    int m = x > y ? x : y; //삼항 연산자

    printf("%d", m);
}

// (조건문) ? (참일경우 실행) : (거짓일 경우 실행) ;
// int m = y
// >>> 2