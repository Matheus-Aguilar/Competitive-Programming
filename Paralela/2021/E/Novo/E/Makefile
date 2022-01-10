CC=g++
FLAGS=-O3 
EXEC=laplace_seq

all: $(EXEC)

$(EXEC):
	$(CC) $(FLAGS) -fopenmp $(EXEC).cpp -o $(EXEC)

clean:
	rm -f laplace_seq *.o
