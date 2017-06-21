#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

struct NODE{
    int data;
    int priority;
};

class PQ{
private: 
    NODE* node;
    int capacity;
    int usedSize;

public:
    PQ(int _capacity){ createNode(_capacity); }
    void createNode(int _capacity);
    void destroy();
    void enQueue();
    void deQueue();

protected:
    void setCapacity(int _capacity);
    void setUsedSize(int _usedSize);
    void swapNode(int idx1, int idx2);

    int getCapacity();
    int setUsedSize();
    int getParent(int idx);
    int getLeftChild(int idx);
};

#endif