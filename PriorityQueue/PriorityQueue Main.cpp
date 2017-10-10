#include <iostream>
#include "PriorityQueue.h"

int main()
{
  std::cout << "Priority Queue: Using Heap" << std::endl;
  HEAP* H = new HEAP(4);
  
  H->enQueue(9);
  H->enQueue(8);
  H->enQueue(3);
//  H->enQueue(7);
//  H->enQueue(6);
//  H->enQueue(2);
//  H->enQueue(5);
//  H->enQueue(4);
//  H->enQueue(1);

  H->PrintHeap();
  H->destroy();
//  delete H;
  return 1;
}
