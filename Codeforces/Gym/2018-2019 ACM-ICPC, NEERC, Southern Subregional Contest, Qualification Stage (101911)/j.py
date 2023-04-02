def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

a, b, x, y = [int(x) for x in input().split(' ')]

g = gcd(x, y)

x //= g
y //= g

l = 1
r = b

r = min(r, (y * a) // x)

li = (l + y - 1) // y
ri = r // y

if l > r or li > ri:
    print(0)
else:
    print(ri - li + 1)