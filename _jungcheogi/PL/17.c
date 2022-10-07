#include <stdio.h>

int f(int i); //함수 선언

void main()
{
    printf("%d %d %d", f(1), f(5), f(-2));
}

int f(int i)
{
    if (i <= 2)
        return 1;
    else
        return f(i - 1) + f(i - 2);
} // 함수 정의? 초기화?

/* 
여기서 알 수 있는 c언어의 특성! 
함수를 먼저 선언하지 않으면 main() 함수에서 사용할 수 없음
and 프로그래밍 언어에서는 main()함수부터 실행함
*/
