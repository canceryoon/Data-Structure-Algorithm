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

    memcpy(tmp, &node[idx1], cpsize);
    memcpy(&node[idx1] , &node[idx2], cpsize);
    memcpy(&node[idx2], tmp, cpsize);

    tree(tmp);
}

void HEAP::printHeap()
{
    for(unsigned int i = 0; i < capacity; i++)
    {
        std::cout << node[i].data << " " ;
    }
}

void HEAP::insertNode(int _data)
{
    int cur_pos = usedSize;
    int parent_pos = getParent(cur_pos);

    if(capacity == usedSize)
    {
        capacity *= 2;
        node = (NODE*)realloc(node, sizeof(NODE) * capacity);
    }

    node[cur_pos].data = _data;

    while(cur_pos > 0 &&  node[cur_pos].data < node[parent_pos].data)
    {
        swapNode(cur_pos, parent_pos);
        cur_pos = parent_pos;
        parent_pos = getParent(cur_pos);
    }

    usedSize++;
}

NODE* deleteMinNode()
{
    int parent_pos = 0;
    int lpos = 0;
    int rpos = 0;

    memset(node[0], 0, sizeof(NODE));
    usedSize -= 1;

    swapNode(0, usedSize);
    lpos = getLeftChild(0);
    rpos = lpos + 1;

    while(1)
    {
        int selectChild = 0;
        if(lpos >= usedSize) break;

        if(rpos >= usedSize)    
            selectChild = rpos;
        else    
            selectChild = (node[lpos].data > node[rpos].data)? rpos : lpos ;
        
        if(node[selectChild].data < node[parent_pos].data)
        {
            swapNode(parent_pos, selectChild);
            parent_pos = selectChild;
        }
        else
            break;

        lpos = getLeftChild(parent_pos);
        rpos = lpos + 1;
    }
    if(usedSize < capacity/2)
    {
        capacity /= 2;
        node = (NODE*)realloc(node, (sizeof(NODE)*capacity));
    }
}