FLAGS=-O3

# CXX=icpc

RM=rm -f

EXEC=sum

all: $(EXEC)

$(EXEC):
	$(CXX) $(FLAGS) $(EXEC).cpp -fopenmp  -o $(EXEC)

clean:
	$(RM) $(EXEC).o $(EXEC)
