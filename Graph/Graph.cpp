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
    destroyEdge(v->adjacencyList);
    v->adjacencyList = e;
  }
  free(v);
}

myEdge* createEdge( myVertex* _from, myVertex* _to, int _wgt )
{
  myEdge* E = (myEdge*)malloc(sizeof(myEdge));
  E->from = _from;
  E->to = _to;
  E->wgt = _wgt;

  return E;
}

void destroyEdge( myEdge* E )
{
  free(E);
}

void addVertex( myGraph* g, myVertex* v )
{
  myVertex* vl = g->vertices;
  if( vl == NULL )
    g->vertices = v;
  else
  {
    while( vl->next != NULL )
      vl = vl->next;
    vl->next = v;
  }
}

void addEdge( myVertex* v, myEdge* e )
{
  if( v->adjacencyList == NULL )
    v->adjacencyList = e;
  else
  {
    while( v->adjacencyList->next != NULL )
      v->adjacencyList = v->adjacencyList->next;
    v->adjacencyList = e;
  }
}

void printGraph( myGraph* g )
{
  myVertex* v = g->vertices;
  myEdge* e = v->adjacencyList;

  if( v == NULL )
    return;

  while( v != NULL )
  {
    std::cout << v->data << " : " ;
    if( e == NULL )
    {
      v = v->next;
      std::cout << " " << std::endl;
      continue;
    }

    while( e != NULL )
    {
      std::cout << e->to->data << "[" << e->wgt << "]" ;
      e = e->next;
    }

    std::cout << " " << std::endl;
    v = v->next;
  }
}