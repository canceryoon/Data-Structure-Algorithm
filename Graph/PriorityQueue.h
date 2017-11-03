#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include "Graph.h"
/*
 * implement Heap Class
 */

struct NODE{
    int _priority;
    void * _data;
};

class HEAP{
private: 
    NODE* node;
    int capacity;
    int usedSize;

public:
    HEAP(int _capacity){ createNode(_capacity); }
    void createNode(int _capacity);
    void destroy();
    void enQueue( NODE _node );
    void deQueue( NODE *pop);
//    void PrintHeap();
    bool isEmpty();
protected:
    void swapNode(int idx1, int idx2);
    int getParent(int idx);
    int getLeftChild(int idx);
};

#endif
