#Graph

CXX = g++

MST : Graph.o PriorityQueue.o DisjointSet.o MST.o
	$(CXX) -o MST MST\ Main.cpp Graph.o PriorityQueue.o MST.o

TOPOLOGICALSORT : Graph.o LinkedList.o TopologicalSort.o
	$(CXX) -o Topologicalsort TopologicalSort\ Main.cpp Graph.o LinkedList.o TopologicalSort.o

TRAVERSAL : Graph.o LinkedQueue.o Traversal.o
	$(CXX) -o Traversal Graph\ Traversal\ Main.cpp Graph.o LinkedQueue.o Traversal.o

GRAPH : Graph.o
	$(CXX) -o Graph Graph\ Main.cpp Graph.o

MST.o :
	$(CXX) -c MST.cpp

DisjointSet.o :
	$(CXX) -c DisjointSet.cpp

PriorityQueue.o :
	$(CXX) -c PriorityQueue.cpp

Traversal.o :
	$(CXX) -c Traversal.cpp  

TopologicalSort.o :
	$(CXX) -c TopologicalSort.cpp

LinkedQueue.o : 
	$(CXX) -c LinkedQueue.cpp
	
LinkedList.o :
	$(CXX) -c LinkedList.cpp

Graph.o :
	$(CXX) -c Graph.cpp

clean : 
	rm -f *.o Graph Traversal Topologicalsort MST
