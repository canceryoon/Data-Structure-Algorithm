#Graph

CXX = g++

TRAVERSAL : Graph.o LinkedQueue.o Traversal.o
	$(CXX) -lm -o Traversal Graph\ Traversal\ Main.cpp Graph.o LinkedQueue.o Traversal.o

GRAPH : Graph.o
	$(CXX) -o Graph Graph\ Main.cpp Graph.o

Graph.o :
	$(CXX) -c Graph.cpp

Traversal.o :
	$(CXX) -c Traversal.cpp  

LinkedQueue.o : 
	$(CXX) -c LinkedQueue.cpp
	
clean : 
	rm -f *.o Graph Traversal
