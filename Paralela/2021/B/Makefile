COMPILER=g++

# Flags
CFLAGS=-O3 -Wall -pedantic -lm

# Files to compile
OBJECTS=est_matriz_seq.cpp

# Executable name
EXE=est_matriz_seq


all: $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(CFLAGS) -fopenmp -o $(EXE)

run:
	./$(EXE)

clean:
	rm $(EXE)
