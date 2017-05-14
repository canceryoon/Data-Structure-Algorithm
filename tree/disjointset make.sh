rm -f DisjointSet.o disjointset

g++ -c DisjointSet.cpp
g++ -o disjointset DisjointSet\ Main.cpp DisjointSet.o