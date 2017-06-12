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

void HEAP::swapNode(int idx1, int idx2)
{
    int cpsize = sizeof(NODE);
    NODE* tmp = (NODE*)malloc(cpsize);

    memcpy(tmp, &h->node[idx1], cpsize);
    memcpy(&h->node[idx1] , &h->node[idx2], cpsize);
    memcpy(&h->node[idx2], tmp, cpsize);

    tree(tmp);
}

void HEAP::printHeap()
{
    for(unsigned int i = 0; i < capacity; i++)
    {
        std::cout << node[i].data << " " ;
    }
}