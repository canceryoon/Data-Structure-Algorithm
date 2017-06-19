#ifndef HEAP_H
#define HEAP_H

typedef struct HEAPNODE{
    int data;
}NODE;

class HEAP {
    NODE* node;
    int capacity;
    int usedSize;

public:
    HEAP(int size)
    {
        node = createNode(size);
        capacity = size;
        usedSize = 0;
    }

    ~HEAP()
    {
        free(node);
    }

    NODE* createNode(int size);
    int deleteMinNode();
    void insertNode(int data);
    void printHeap();

private:
    int getParent(int idx);
    int getLeftChild(int idx);
    void swapNode(int idx1, int idx2);

};

#endif