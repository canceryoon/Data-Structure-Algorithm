#include "MST.h"

void prim( myGraph *g, myVertex *startV, myGraph *mst )
{
  int i = 0;
  NODE startNode = { 0, startV };
  HEAP pq(10);
  myVertex *currentV = NULL;
  myEdge *currentE = NULL;
  
  int *wgt = (int*)malloc(sizeof(int)*g->vertexCnt);
  myVertex **MSTVertices = (myVertex**)malloc(sizeof(myVertex*)*g->vertexCnt);
  // f : Fringes
  myVertex **f = (myVertex**)malloc(sizeof(myVertex*)*g->vertexCnt);
  // p : Precedences 
  myVertex **p = (myVertex**)malloc(sizeof(myVertex*)*g->vertexCnt);

  currentV = g->vertices;
  while( currentV != NULL )
  {
    myVertex *newV = createVertex( currentV->data );
    addVertex(mst, newV);
    wgt[i] = MAX_WGT;
    f[i] = NULL;
    p[i] = NULL;
    MSTVertices[i] = newV;
    currentV = currentV->next;
    i++;
  }

  pq.enQueue(startNode);
  wgt[startV->idx] = 0;

  while( !pq.isEmpty() )
  {
    NODE pop;
    pq.deQueue(&pop);
    
    currentV = pop._data;
    currentE = currentV->adjacencyList;
    f[currentV->idx] = currentV;
    
    while( currentE != NULL )
    {
      myVertex *toV = currentE->to;
      if( !f[toV->idx] && currentE->wgt < wgt[toV->idx] )
      {
	NODE nNode = { currentE->wgt, toV };
	pq.enQueue(nNode);
	p[toV->idx] = currentE->from;
	wgt[toV->idx] = currentE->wgt;
      }
      currentE = currentE->next;
    }
  }

  for( i = 0; i < g->vertexCnt; i++ )
  {
    int fIdx, tIdx;

    if(!p[i])
      continue;

    fIdx = p[i]->idx;
    tIdx = i;
    addEdge(MSTVertices[fIdx], createEdge(MSTVertices[fIdx], MSTVertices[tIdx], wgt[i]) );
    addEdge(MSTVertices[tIdx], createEdge(MSTVertices[tIdx], MSTVertices[tIdx], wgt[i]) );
  }

  free(wgt);
  free(MSTVertices);
  free(f);
  free(p);
}
