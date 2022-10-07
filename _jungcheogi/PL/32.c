#include <stdio.h>

void main()
{
    int a = 105;
    char c = 'Z';

    switch (a / 10) // a/10 = 10.5 -> c언어는 정수형끼리 계산시 정수형 반환 -> 10 반환
    {
    case 10:
        // break가 없으니 다음 줄 실행
    case 9:
        c = 'A';
        break; // 여기서 해당 구문 빠져나옴
    case 8:
        c = 'B';
        break;
    default:
        c = 'F';
    }
    printf("%c\n", c); // >>> 'A'
}
