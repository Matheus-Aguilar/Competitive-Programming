COMPILER=gcc

# Flags
CFLAGS=-O3 -Wall -std=gnu11 -pedantic -lm

# Files to compile
OBJECTS=est_matriz_seq.c

# Executable name
EXE=est_matriz_seq


all: $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(CFLAGS) -o $(EXE)

run:
	./$(EXE)

clean:
	rm $(EXE)
