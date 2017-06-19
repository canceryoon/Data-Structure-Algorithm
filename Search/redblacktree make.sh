rm -f *.o redblacktree 
g++ -c RedBlackTree.cpp
g++ -c RedBlackTree\ Main.cpp
g++ -o redblacktree RedBlackTree.o RedBlackTree\ Main.o
