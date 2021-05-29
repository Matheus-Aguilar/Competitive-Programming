.PHONY = all clean
FLAGS  = -O3 -Wall -fopenmp

all: permutations

permutations: permutations.cc
	$(CXX) $(FLAGS) permutations.cc -o permutations

clean:
	rm -rf permutations

