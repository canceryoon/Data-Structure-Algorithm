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
  E->next = NULL;
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
  v->idx = g->vertexCnt++;
}

void addEdge( myVertex* v, myEdge* e )
{
  if( v->adjacencyList == NULL )
  {
    v->adjacencyList = e;
  }
  else
  {
    myEdge* _tmp = v->adjacencyList ;
    while( _tmp->next != NULL )
      _tmp = _tmp->next;
    _tmp->next = e;
  }
}

void printGraph( myGraph* g )
{
  myVertex* v = g->vertices;
  myEdge* e = NULL;

  if( v == NULL )
    return;

  while( v != NULL )
  {
    std::cout << v->data << " : " ;
    if( (e = v->adjacencyList) == NULL )
    {
      v = v->next;
			std::cout << " " << std::endl;
      continue;
    }

    while( e != NULL )
    {
      std::cout << e->to->data << "[" << e->wgt << "] " ;
      e = e->next;
    }

    v = v->next;
    std::cout << " " << std::endl;
  }
}
