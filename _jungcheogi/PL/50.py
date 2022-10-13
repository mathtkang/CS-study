sum = 0
a = [1, 2, 3, 4, 5, 6, 7, 8]
b = a[::2]
for i in range(0, 3):
    sum += b[i]
print(sum)
