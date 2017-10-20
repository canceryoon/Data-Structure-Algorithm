#include "Traversal.h"

void DFS( myVertex* v )
{
  myEdge* E = NULL;
  cout << v->data << " " ;

  v->visited = Visited;
  E = v->adjacencyList;

  while( E != NULL )
  { 
    if( E->to != NULL && E->to->visited == NotVisited )
      DFS(E->to);

    E = E->next;
  }
}
