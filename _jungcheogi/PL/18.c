/*
주의할 점!
return N -> 은 출력하는 값이 아니다!
*/
#include <stdio.h>

int fn(int n)
{
    if (n <= 0)
        return 1;
    else
        printf("%d ", n);

    fn(n - 1);
}

int main()
{
    fn(5);
    // fn(5) -> 5 출력 후 fn(4) 호출
    // fn(4) -> 4 출력 후 fn(3) 호출
    // fn(3) -> 3 출력 후 fn(2) 호출
    // fn(2) -> 2 출력 후 fn(1) 호출
    // fn(1) -> 1 출력 후 fn(0) 호출
    // fn(0) -> return 1 (출력이 아니라 return이다!) 후 함수 종료
    // 따라서 출력되는 값은 >>> 5 4 3 2 1
    return 0;
}

// 요기서는 void가 아니라 int main()이구나!
// 참고 블로그: https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tipsware&logNo=221243513396
