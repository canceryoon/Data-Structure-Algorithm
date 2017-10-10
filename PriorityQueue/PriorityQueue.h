#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

/*
 * implement Heap Class
 */

struct NODE{
    int _data;
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
    void enQueue( int _data );
    void deQueue();
    void PrintHeap();

protected:
    void swapNode(int idx1, int idx2);
    int getParent(int idx);
    int getLeftChild(int idx);
};

#endif
