#include <stdio.h>

int fn(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fn(n - 1);
}
// fn안에서 fn을 한번 더 출력하는 재귀함수
// 더 정확하게는, 팩토리얼 함수!

void main()
{
    printf("%d", fn(4));
    // fn(4) = 4*fn(3)
    //       = 4*3*fn(2)
    //       = 4*3*2*fn(1)
    //       = 4*3*2*1 = 24
}