#include<iostream>
#include "Binary Node.h"
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
class Tree
{
private:
    Node* head;
    int cnt;
public:
    Tree(){ this->head = NULL; cnt = 0;}
    Tree(Node* _node){ this->head = _node ; cnt = 1;}

    Node* getHead();
    void setHead(Node* _node);
    void insertTree(Node* _node);
    Node* findaddrTree(int level, int addr, int depth);
    void printTree();

};
#endif
