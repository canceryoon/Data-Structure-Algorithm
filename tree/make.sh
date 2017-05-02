g++ -c Binary\ Node.cpp 
g++ -c Binary\ Tree.cpp Binary\ Node.o 
g++ -o btree Binary\ Tree\ main.cpp Binary\ Tree.o Binary\ Node.o
