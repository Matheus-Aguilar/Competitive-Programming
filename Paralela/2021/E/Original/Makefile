CC=gcc
FLAGS=-O3 
EXEC=laplace_seq

all: $(EXEC)

$(EXEC):
	$(CC) $(FLAGS) $(EXEC).c   -c -o $(EXEC).o
	$(CC) $(FLAGS) $(EXEC).o -o $(EXEC)

clean:
	rm -f laplace_seq *.o
