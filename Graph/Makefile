#Graph

CXX = g++

TRAVERSAL : Graph.o Linked\ Queue.o Traversal.o
	$(CXX) -o Traversal Graph\ Traversal\ Main.cpp  Graph.o Linked\ Queue.o Traversal.o

GRAPH : Graph.o
	$(CXX) -o Graph Graph\ Main.cpp Graph.o

Graph.o :
	$(CXX) -c Graph.cpp

Linked Queue.o :
	$(CXX) -c Linked\ Queue.cpp

Traversal.o :
	$(CXX) -c Traversal.cpp 

clean : 
	rm -f *.o Graph
