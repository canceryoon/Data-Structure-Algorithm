#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "PriorityQueue.h"

void HEAP::createNode( int _capacity )
{
  usedSize = 0;
  capacity = _capacity;
  node = (NODE*)malloc(sizeof(NODE)*capacity); 
}

void HEAP::destroy()
{
  free(node);
}

void HEAP::enQueue( int _data )
{
  int curPos = usedSize;
  int parentPos = getParent( curPos );
    std::cout << "enQueue " <<  _data << std::endl;
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

void HEAP::swapNode( int idx1, int idx2 )
{
  NODE* tmp = (NODE*)malloc(sizeof(NODE));
  memcpy(tmp, &node[idx1], sizeof(NODE) );
  memcpy(&node[idx1], &node[idx2], sizeof(NODE) );
  memcpy(&node[idx2], tmp, sizeof(NODE) );
  free(tmp);
}

int HEAP::getLeftChild( int idx )
{
  return (2*idx) + 1;
}

int HEAP::getParent( int idx )
{
  return (2*idx) + 1;
}

void HEAP::deQueue()
{
  int parentPos = 0;
  int LeftPos = 0;
  int RightPos = 0;
  
  memset(&node[0], 0, sizeof(NODE));
  usedSize--;
  swapNode( 0, usedSize );

  LeftPos = getLeftChild( 0 );
  RightPos = LeftPos + 1;
  
  while(1)
  {
    int selectChild = 0;
    
    if( LeftPos >= usedSize ) break;
    if( RightPos >= usedSize ) 
    {
      selectChild = RightPos;
    }
    else
    {
      if( node[LeftPos]._data > node[RightPos]._data )
	selectChild = RightPos;
      else
	selectChild = LeftPos;
    }

    if( node[selectChild]._data < node[parentPos]._data )
    {
      swapNode( parentPos, selectChild );
      parentPos = selectChild;
    }
    else
      break;

    LeftPos = getLeftChild( parentPos );
    RightPos = LeftPos + 1;
  }
}

void HEAP::PrintHeap()
{
  unsigned int i = 0;
std::cout << usedSize << std::endl;
  for( i; i < usedSize; i++ )
  {
    std::cout << i << "data : " << node[i]._data << " ";
  }
  std::cout << " " << std::endl;
}

