FLAGS=-O3 -Wall -fopenmp
OUT=primetest

all: primetest

primetest: primetest.cpp
	g++ primetest.cpp $(FLAGS) -lm -o $(OUT)

clean:
	rm $(OUT)
