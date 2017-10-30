#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "PriorityQueue.h"

void HEAP::createNode( int _capacity )
{
  usedSize = 0;
  capacity = _capacity;
  node = (NODE*)malloc(sizeof(NODE)*(capacity)); 
}

void HEAP::destroy()
{
  free(node);
}

void HEAP::enQueue( NODE _node )
{
  int curPos = usedSize;
  int parentPos = getParent( curPos );
  if( usedSize != capacity )
  {
    node[curPos] = _node; 
    while( curPos > 0 && node[curPos]._priority < node[parentPos]._priority )
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
  return (int)((idx-1)/2);
}

void HEAP::deQueue( NODE *pop )
{
  int parentPos = 0;
  int LeftPos = 0;
  int RightPos = 0;
  
	memcpy(pop, &node[0], sizeof(NODE));
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
      selectChild = LeftPos;
    }
    else
    {
      if( node[LeftPos]._priority > node[RightPos]._priority )
				selectChild = RightPos;
      else
				selectChild = LeftPos;
    }

    if( node[selectChild]._priority < node[parentPos]._priority )
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
  int i = 0;
  for( i = 0; i < usedSize; i++ )
  {
    std::cout << node[i]._priority; 
    printf(" [%s] ", node[i]._data );
  }
  std::cout << " " << std::endl;
}

bool HEAP::isEmpty()
{
	return (usedSize == 0);
}
