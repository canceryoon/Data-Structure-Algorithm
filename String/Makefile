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

KMP : KnuthMorrisPratt.o
	$(CXX) -o KMP KMP\ Main.cpp KnuthMorrisPratt.o

KnuthMorrisPratt.o :
	$(CXX) -c KnuthMorrisPratt.cpp 

BM : BoyerMoore.o
	$(CXX) -o BM BM\ Main.cpp BoyerMoore.o

BoyerMoore.o :
	$(CXX) -c BoyerMoore.cpp

clean : 
	rm -rf *.o BruteForce KarpRabin KMP
