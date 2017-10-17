#include "Graph.h"

myGraph* createGraph()
{
  myGraph* graph = (myGraph*)malloc(sizeof(myGraph));
  graph->vertices = NULL;
  graph->vertexCnt = 0;

  return graph;
}

void destroyGraph( myGraph* G )
{
  while( G->vertices != NULL )
  {
    myVertex* v = G->vertices->next;
    destroyVertex(G->vertices);
    G->vertices = v;
  }
  free(G);
}

myVertex* createVertex( int _data )
{
  myVertex* v = (myVertex*)malloc(sizeof(myVertex));

  v->data = _data;
  v->next = NULL;
  v->adjacencyList = NULL;
  v->visited = NotVisited;
  v->idx = -1;

  return v;
}

void destroyVertex( myVertex* v )
{
  while( v->adjacencyList != NULL )
  {
    myEdge* e = v->adjacencyList->next;
    destroyEdge(v-adjacencyList);
    v->adjacencyList = e;
  }
  free(v);
}
