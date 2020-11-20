CXXFLAGS=-O3 -std=c++11 -fopenmp

EXEC=tropical

all: $(EXEC)

$(EXEC): tropical.cpp
	$(CXX) $(CXXFLAGS) $(EXEC).cpp -c -o $(EXEC).o
	$(CXX) $(CXXFLAGS) $(EXEC).o -o $(EXEC)

clean:
	$(RM) $(EXEC).o $(EXEC)
