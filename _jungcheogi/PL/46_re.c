#include <stdio.h>

void main()
{
    int a = 10;
    int *p = &a;              //포인터변수 p: 변수 a의 주솟값을 할당
    printf("%d %d\n", a, *p); //출력할 때는, 포인터 변수가 가리키는 변수 a의 값을 출력

    a = 30;
    printf("%d %d\n", a, *p); //마찬가지로, 포인터 변수가 a를 가리키고 있기 때문에 출력시 변한 변수 a의 값을 출력
}

// 다시