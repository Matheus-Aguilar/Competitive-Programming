from math import log2
m, p, j, x = map(float, input().split())
p = p/100
j = j/100
print(x/(m * j), 1-p)
print(log2(x/(m * j)), log2(1-p))
ans = int(log2(x/(m * j))/log2(1-p))
if ans < 0:
    ans = 0
print(ans)