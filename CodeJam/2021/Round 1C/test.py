from random import randint

N = 10

print(N)

for i in range(N):
    print(format(randint(0, 15), 'b'), format(randint(0, 15), 'b'))