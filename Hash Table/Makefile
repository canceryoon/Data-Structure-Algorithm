# HASHTABLE
# make HASHTABLE : Build normal Hash Table
# make CHAININGHASH : Build chaining Hash Table

CXX = g++

HASHTABLE : HashTable.o 
	$(CXX) -o HashTable HashTable\ Main.cpp HashTable.o
	
HashTable.o :
	$(CXX) -c HashTable.cpp
	
CHAININGHASH : ChainingHash.o
	$(CXX) -o ChainingHash ChainingHash\ Main.cpp ChainingHash.o

ChainingHash.o :
	$(CXX) -c ChainingHash.cpp

OPENADDRHASH : OpenAddrHash.o
	$(CXX) -o OpenAddrHash OpenAddrHash\ Main.cpp OpenAddrHash.o

OpenAddrHash.o :
	$(CXX) -c OpenAddrhash.cpp

clean:
	rm -rf *.o HashTable ChainingHash
