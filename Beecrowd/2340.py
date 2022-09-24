import math
n = int(input())
melhor = -1
maior = -1
for i in range(n):
    d, c = map(int, input().split())
    t = math.log2(d) * c
    if t > maior:
        maior = t
        melhor = i
print(melhor)