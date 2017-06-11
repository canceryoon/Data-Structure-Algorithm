#include <iostream>
#include "Heap.h"

NODE* HEAP::createNode(int size)
{
    NODE* nNode = (NODE*)malloc(sizeof(NODE) * size);
    return nNode;
}

int HEAP::getParent(int idx)
{
    return (int)((idx-1)/2);
}

int HEAP::getLeftChild(int idx)
{
    return (2 * idx) + 1;
}