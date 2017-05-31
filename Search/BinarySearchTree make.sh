rm -f *.o binarysearchtree
g++ -c BinarySearchTree.cpp 
g++ -c BinarySearchTree\ Main.cpp
g++ -o binarysearchtree BinarySearchTree\ Main.o BinarySearchTree.o