a = 10
b = 5
# 파이썬에서는 이렇게 대입연산자로, 두 변수의 값을 바꾸는게 가능하지만, 다른 언어의 경우 새로운 변수(temp)를 활용해서 바꿔야한다.
a, b = b, a
print(a)
print(b)
'''
[다른 언어의 예시]
int a, b;
temp = a
a = b
b = temp
'''
