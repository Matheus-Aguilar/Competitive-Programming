FLAGS=-O3 -Wall -std=c11 -fopenmp
OUT=primetest

all: primetest

primetest: primetest.c
	$(CC) primetest.c $(FLAGS) -lm -o $(OUT)

clean:
	rm $(OUT)
