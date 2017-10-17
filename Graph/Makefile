#Graph

CXX = g++

GRAPH : Graph.o
	$(CXX) -o Graph Graph\ Main.cpp Graph.o

Graph.o :
	$(CXX) -c Graph.cpp

clean : 
	rm -f *.o Graph
