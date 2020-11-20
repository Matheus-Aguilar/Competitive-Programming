FLAGS=-O3 -lssl -lcrypto -fopenmp

CC=g++

RM=rm -f

EXEC=password_bf

all: $(EXEC)

$(EXEC):
	$(CC) $(FLAGS) password_bf.cpp -c -o password_bf.o
	$(CC) password_bf.o -o $(EXEC) $(FLAGS)

run:
	./$(EXEC)

clean:
	$(RM) password_bf.o $(EXEC)
