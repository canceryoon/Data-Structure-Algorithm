#include "Traversal.h"

void DFS( myVertex* v )
{
  myEdge* E = NULL;
  std::cout << v->data << " " ;

  v->visited = Visited;
  E = v->adjacencyList;

  while( E != NULL )
  { 
    if( E->to != NULL && E->to->visited == NotVisited )
      DFS(E->to);

    E = E->next;
  }
}

void BFS( myVertex* v, LQueue* lq)
{
  myEdge* E = NULL;
  std::cout << v->data << " : " ;
  
  v->visited = Visited;
  lq->InQueue(v);

  while( !lq->IsEmpty() )
  {
    Node* pop = lq->DeQueue();
    v = pop->_data;
    E = v->adjacencyList;

    while( E != NULL )
    {
      v = E->to;
      if( v != NULL && v->visited == NotVisited )
      {
	std::cout << v->data << " ";
	v->visited = Visited;
	lq->InQueue(v);
      }
      E = E->next;
    }
  }
  
}

