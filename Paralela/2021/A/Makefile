FLAGS=-O3 -std=c++11
CXX=g++

ALL: brute_isomorphism

brute_isomorphism: brute_isomorphism.o
	$(CXX) brute_isomorphism.o -o brute_isomorphism

brute_isomorphism.o: brute_isomorphism.cpp
	$(CXX) -c brute_isomorphism.cpp -o brute_isomorphism.o

clean:
	rm -rf brute_isomorphism *.o 
