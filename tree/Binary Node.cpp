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