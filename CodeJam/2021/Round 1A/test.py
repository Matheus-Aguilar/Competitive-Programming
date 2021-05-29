from miller_rabin import miller_rabin as prime
from random import randint as rand

N = 500
M = 100
cont = 0

P = []
C = []

print(1)

while M > 0:
    c = rand(1, M)
    M -= c

    p = 4

    while not prime(p):
        p = rand(2, 499)
    
    P.append(p)
    C.append(c)

    cont += 1

print(cont)

for i in range(cont):
    print(P[i], C[i])


