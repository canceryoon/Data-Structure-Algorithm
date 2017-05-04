#include<iostream>
#include"Binary Tree.h"

static int findInsertTreeLevel(int cnt, int exponent)
{
    int _exponent = ( exponent == -1 )? 1 : 2 << exponent ;
    if( cnt > _exponent ) return findInsertTreeLevel(( cnt - _exponent), ++exponent);
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
    int addr = this->cnt + 1;
    int level = findInsertTreeLevel(addr, -1);
    this->getHead()->insertNode(level, addr, 0, node);
    this->cnt++;    
    
}


void Tree::printTree(int depth)
{
    this->getHead()->printNode(depth);
}