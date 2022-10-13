#include <stdio.h>
void main()
{
    char *str = "zjavb";
    int i;
    for (i = 4; i >= 0; i--)
    {
        printf("%c", *(str + i));
        // i=4; *(str+4): str변수의 4번째 값을 가리킴: "b"
    }
}
// >>> "bvajz"
// 여기 다시