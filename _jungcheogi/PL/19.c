/* 
18번 문제와 다른 점
fn(int n)함수에서 return으로 값을 반환 한 다음, printf()함수로 값을 출력해줘야 함!
*/
#include <stdio.h>

int fn(int n)
{
    if (n <= 0)
        return 0;
    return n + fn(n - 1);
}

void main()
{
    printf("%d", fn(12));
}
