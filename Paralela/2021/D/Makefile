CXX=gcc
CXXFLAGS=-O3 -std=c++11 -w
EXEC=johnson
all: $(EXEC)

$(EXEC):
	$(CXX) $(CXXFLAGS) $(EXEC).c -c -o $(EXEC).o
	$(CXX) $(CXXFLAGS) $(EXEC).o -o $(EXEC)

clean:
	$(RM) $(EXEC).o $(EXEC)
