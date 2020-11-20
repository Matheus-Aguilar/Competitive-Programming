FLAGS=-O3 -std=c11 -Wall -fopenmp
OUT=primetest

all: primetest

primetest: primetest.c
	$(CC) primetest.c $(FLAGS) -lm -o $(OUT)

clean:
	rm $(OUT)
