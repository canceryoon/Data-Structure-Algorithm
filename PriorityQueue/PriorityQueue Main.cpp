#include <iostream>
#include "PriorityQueue.h"

int main()
{
  std::cout << "Priority Queue: Using Heap" << std::endl;
  HEAP H(5);
  
  H.enQueue(9);
  H.enQueue(8);
  H.enQueue(5);
  H.enQueue(3);
  H.enQueue(7);
  H.enQueue(1);

  H.PrintHeap();
  H.deQueue();
  H.PrintHeap();
  H.enQueue(1);
  H.PrintHeap();

  H.destroy();
  return 1;
}
