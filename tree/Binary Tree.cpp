#include<iostream>
#include"Binary Tree.h"

static int findInsertTreeLevel(int cnt, int exponent)
{
    if( cnt > (2 << exponent)) return findInsertTreeLevel(( cnt - (2<<exponent++)), exponent);
    else return exponent+1;
}

Node* Tree::getHead()
{
    return this->head;
}

void Tree:: setHead(Node* _node)
{
    this->head = _node;
    this->cnt = 1;
}

void Tree::insertTree(Node* node)
{
    std::cout << this->cnt << std::endl;
    int level = findInsertTreeLevel(this->cnt+1, -1);
    int addr = this->cnt + 1;
    
    this->getHead()->findaddrNode(level, addr, 0, node);
    this->cnt++;    
}


void Tree::printTree(int depth)
{
    this->getHead()->printNode(depth);
}