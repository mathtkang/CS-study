#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[2][2] = {{11, 22},
                   {44, 55}}; //배열 선언 및 초기화
    int i, sum = 0;
    int *p;   //포인터 변수 선언
    p = a[0]; //포인터 변수 초기화

    for (i = 1; i < 4; i++)
        sum += *(p + i);
    printf("%d", sum);
    return 0;
}

// 여기 다시