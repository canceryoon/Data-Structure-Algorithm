#include <iostream>
#include "PriorityQueue.h"

void HEAP::createNode( int _capacity )
{
  usedSize = 0;
  capacity = _capacity;
  node = new NODE[capacity];
}

void HEAP::destroy()
{
  delete []node;
  usedSize = 0;
  capacity = 0;
}

void HEAP::enQueue( int _data )
{
  int curPos = usedSize;
  int parentPos = getParent( curPos );
  if( usedSize != capacity )
  {
    node[curPos]._data = _data; 
    while( curPos > 0 && node[curPos]._data < node[parentPos]._data )
    {
      swapNode( curPos, parentPos );
      curPos = parentPos;
      parentPos = getParent( curPos );
    }
    usedSize++;
    return ;
  }

  std::cout << "Full Heap. (" << usedSize << ")" << std::endl;
}
