#include<iostream>
#include"Binary Tree.h"

static int findInsertTreeLevel(int cnt, int exponent)
{
    if( cnt > (2 << exponent)) return findInsertTreeLevel(( cnt - (2<<exponent)), exponent++);
    else return exponent;
}

Node* Tree::getHead()
{
    return this->head;
}
void Tree::setHead(Node* _node)
{
    this->head = _node;
    this->cnt = 1;
}

Node* Tree::findaddrTree(int level, int addr, int depth)
{
    Tree* nTree;
    int total = 2 << ((level == 0)? level : level - 1);
    if( addr > total) addr = addr - (2 << (level - 1));
    if( level != depth )
    {
        if( (total >> 1) < addr )
        {
            nTree->setHead(this->getHead()->getRC());
            nTree->findaddrTree(level-1, addr, depth+1);
        }
        else
        {
            nTree->setHead(this->getHead()->getLC());
            nTree->findaddrTree(level-1, addr, depth+1);
        }
    }
    else
    {
         if( (total >> 1) < addr )
        {
            std::cout << "Left Child Insert " << std::endl;
        }
        else
        {
            std::cout << "Right Child Insert " << std::endl;
        }
        return NULL;
    }
    
}

void Tree::insertTree(Node* node)
{
    int level = findInsertTreeLevel(this->cnt, 0) + 1;
    int addr = this->cnt;
    for(unsigned int i = 0; i < level; i++)
    {
        addr -= 2 << i ;
    }

    std::cout << this->cnt << " " << level << " " << addr << std::endl;
    this->findaddrTree(level, addr, 1);
}


void Tree::printTree()
{
    std::cout << "Print Tree Func." << std::endl;
}