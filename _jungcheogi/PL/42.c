#include <stdio.h>

void main()
{
    int i = 1;      //초깃값 역할
    for (; i < 10;) //만약 for문 안에 탈출 조건이 없다면 무한반복(while문과 동일)이다.
    {
        switch (i % 2)
        {
        case 0:
            printf("짝수: %d\n", i);
            break; // 이 break는 switch 구문의 탈출을 의미!
        default:
            printf("홀수: %d\n", i);
        }
        i += 3; //증감 역할
    }
}
// 다시풀기(실수함!)