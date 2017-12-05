#String
#Using linux

CXX = g++

BruteForce : BruteForce.o 
	$(CXX) -o BruteForce BruteForce\ Main.cpp BruteForce.o

BruteForce.o :
	$(CXX) -c BruteForce.cpp

KarpRabin : KarpRabin.o
	$(CXX) -o KarpRabin KarpRabin\ Main.cpp KarpRabin.o

KarpRabin.o :
	$(CXX) -c KarpRabin.cpp

clean : 
	rm -rf *.o BruteForce
