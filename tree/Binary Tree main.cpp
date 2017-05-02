#include<iostream>
#include "Binary Tree.h"

int main()
{
    Node _head('A');
    Node ihead('B');
    Tree head(&_head);

    head.insertTree(&ihead);
}