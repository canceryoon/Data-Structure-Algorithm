#include <iostream>
#include "Heap.h"

int main()
{
    HEAP heap(5);
    int minNode;

    heap.insertNode(3);
    heap.insertNode(4);
    heap.insertNode(2);
    heap.insertNode(9);
    heap.insertNode(0);
    heap.insertNode(5);

    heap.printHeap();

    minNode = heap.deleteMinNode();
    std::cout << "Deleted Min Node Data: " << minNode << std::endl;

    heap.printHeap();
}