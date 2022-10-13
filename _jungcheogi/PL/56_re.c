#include <stdio.h>

void main()
{
    int *pnum, Num1 = 200, Num2 = 300;
    pnum = &Num1;  //pnum이 Num1의 주소를 저장한다.
    (*pnum) += 40; //pnum이 가리키고(*) 있는 값(Num1)을 40 증가 시킨다 >>> Num1은 240이 된다.
    pnum = &Num2;  //pnum이 Num2의 주소를 저장한다.
    (*pnum) -= 50; //pnum이 가리키고(*) 있는 값(Num2)을 50 감소 시킨다 >>> Num2은 250이 된다.
    printf("%d %d", Num1, Num2);
}

// 맞았지만, 다시!