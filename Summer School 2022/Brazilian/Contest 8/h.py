m = int(input())

n = 0
s = 0
ok = False

for i in range(3, 60):
    sum = 0
    s = 1

    while sum < m:
        sum += (s ** (i - 1))
        s += 1
    
    if sum == m:
        n = i
        s -= 1
        ok = True
        break

if ok:
    print(n, s)
else:
    print("impossible")