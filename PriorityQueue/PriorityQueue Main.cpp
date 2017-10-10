#include <iostream>
#include "PriorityQueue.h"

int main()
{
  std::cout << "Priority Queue: Using Heap" << std::endl;
  HEAP H(5);
 
  NODE nodes[6] = 
  {
    {12, (void*)"테스트"},
    {2, (void*)"설계"},
    {22, (void*)"디자인"},
    {7, (void*)"개발"},
    {34, (void*)"버그픽스"},
    {50, (void*)"뒤엎기"}
  }; 
  
  H.enQueue(nodes[0]);
  H.enQueue(nodes[1]);
  H.enQueue(nodes[2]);
  H.enQueue(nodes[3]);
  H.enQueue(nodes[4]);
  H.enQueue(nodes[5]);

  H.PrintHeap();
  H.deQueue();
  H.PrintHeap();

  H.enQueue(nodes[5]);
  H.PrintHeap();

  H.destroy();

  return 1;
}
