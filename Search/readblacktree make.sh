rm -f *.o readblacktree 
g++ -c ReadBlackTree.o
g++ -c ReadBlackTree\ Main.o
g++ -o readblacktree ReadBlackTree.o ReadBlackTree\ Main.o