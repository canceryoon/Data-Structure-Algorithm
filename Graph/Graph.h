#ifndef GRAPH_H
#define GRAPH_H

enum VisitMode
{
  Visited,
  NotVisited
};

typedef struct myvertex
{
  int data;
  int visited;
  int idx;

  struct Vertex* next;
  struct Edge* adjacencyList;
}myVertex;

typedef struct myedge
{
  int wgt;
  struct Edge* next;
  
  Vertex* from;
  Vertex* to;
}myEdge;

typedef struct mygraph
{
  Vertex* vertices;
  int vertexCnt;
}myGraph;

myGraph* createGraph();
void destroyGraph( myGraph* G);

myVertex* createVertex( int _data );
void destroyVertex( myVertex* V );

myEdge* createEdge( myVertex* from, myVertex* to, int wgt );
void destroyEdge( myEdge* E );

void addVertex( myGraph* G, myVertex* V );
void addEdge( myVertex* V, myEdge* E );
void printGraph( myGraph* G );

#endif
