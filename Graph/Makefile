#Graph

CXX = g++

TRAVERSAL : Graph.o Traversal.o
	$(CXX) -v -o Traversal Graph\ Traversal\ Main.cpp Graph.o Traversal.o

GRAPH : Graph.o
	$(CXX) -o Graph Graph\ Main.cpp Graph.o

Graph.o :
	$(CXX) -c Graph.cpp

Traversal.o :
	$(CXX) -c Traversal.cpp 

clean : 
	rm -f *.o Graph Traversal
