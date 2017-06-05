rm -f *.o redblacktree 
g++ -c RedBlackTree.o
g++ -c RedBlackTree\ Main.o
g++ -o redblacktree RedBlackTree.o RedBlackTree\ Main.o