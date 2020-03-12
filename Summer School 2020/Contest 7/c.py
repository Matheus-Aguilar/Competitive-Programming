n = int(input())
n = n + 1

num = 1
for i in range(n + 2, 2 * n + 1):
    num = num * i

dem = 1
for i in range(1, n + 1):
    dem = dem * i

print(num//dem)