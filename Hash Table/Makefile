# HASHTABLE

CXX = g++

HASHTABLE : HashTable.o 
	$(CXX) -o HashTable HashTable\ Main.cpp HashTable.o
	
HashTable.o :
	$(CXX) -c HashTable.cpp
	
CHAININGHASH : ChainingHash.o
	$(CXX) -o ChainingHash ChainingHash\ Main.cpp ChainingHash.o

ChainingHash.o :
	$(CXX) -c ChainingHash.cpp
clean:
	rm -rf *.o HashTable ChainingHash
