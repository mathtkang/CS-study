#include <stdio.h>

struct KEY
{
    int a;
    int b;
}; // KEY라는 이름의 구조체 타입을 정의

void main()
{
    struct KEY y; // KEY구조체 타입을 가진 변수 y 선언
    // (한번에) struct KEY *p = &y;
    struct KEY *p; // 포인터 p 선언
    p = &y;        // 선언된 포인터 변수(p)에 y주소값 저장

    y.a = 100; //구조체 변수 y 안에 포함된 변수들에 값 대입
    y.b = 200;

    printf("%d", p->a); // p는 포인터니까, ->를 이용해서 접근

    // . : 일반 구조체 변수로 접근할 때
    // -> : 구조체 포인터로 접근할 때
};