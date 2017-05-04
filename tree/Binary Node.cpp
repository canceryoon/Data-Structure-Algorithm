#include<iostream>
#include"Binary Node.h"

char Node::getData()
{
    return this->data;
}

void Node::setData(char _data)
{
    this->data = _data;
}

void Node::setLC(Node* lNode)
{
    this->LChiled = lNode;
}

void Node::setRC(Node* lNode)
{
    this->RChiled = lNode;
}

Node* Node::getLC()
{
    return this->LChiled;
}

Node* Node::getRC()
{
    return this->RChiled;
}

void Node::printNode(int depth)
{
    for(int i = 0; i < depth; i++) std::cout << " " ;
    std::cout << this->getData() << std::endl;

    if( this->getLC() != NULL ) this->getLC()->printNode( depth+1);
    if( this->getRC() != NULL ) this->getRC()->printNode( depth+1);
}


void Node::insertNode(int level, int addr, int depth, Node* inode)
{
    int total = 2 * (level - depth);
    if( addr >= total ) addr = addr - total + depth + 1;
    if( level == ++depth )
    {
        if( (total >> 1) < addr )
        {
            return this->setRC(inode);
        }
        else
        {   
            return this->setLC(inode);   
        }
    }
    else
    {
        if( (total >> 1) < addr )
        {
            this->getRC()->insertNode(level, addr, depth, inode);
        }
        else
        {
            this->getLC()->insertNode(level, addr, depth, inode);
        }
    }
}