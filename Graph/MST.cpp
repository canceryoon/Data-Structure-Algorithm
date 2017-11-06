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
    
    currentV = (myVertex*)pop._data;
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
    addEdge(MSTVertices[tIdx], createEdge(MSTVertices[tIdx], MSTVertices[fIdx], wgt[i]) );
  }

  free(wgt);
  free(MSTVertices);
  free(f);
  free(p);
}

void kruskal( myGraph *g, myGraph *mst )
{
  int i = 0;
  myVertex *currentV = NULL;
  myVertex **mstV = (myVertex**)malloc(sizeof(myVertex*)*g->vertexCnt);
  DisjointSet **vSet = (DisjointSet**)malloc(sizeof(DisjointSet*)*g->vertexCnt);
  HEAP pq(10);

  currentV = g->vertices;
  while( currentV != NULL )
  {
    myEdge *currentE;

    vSet[i] = DS_MakeSet(currentV);
    mstV[i] = createVertex(currentV->data);
    addVertex(mst, mstV[i]);

    currentE = currentV->adjacencyList;
    while( currentE != NULL )
    {
      NODE nNode = { currentE->wgt, currentE };
      pq.enQueue(nNode);
      currentE = currentE->next;
    }

    i++;
    currentV = currentV->next;
  }

  while( !pq.isEmpty() )
  {
    myEdge *currentE;
    int fIdx, tIdx;
    NODE pop;

    pq.deQueue(&pop);
    currentE = (myEdge*)pop._data;
    fIdx = currentE->from->idx;
    tIdx = currentE->to->idx;

    if( DS_FindSet(vSet[fIdx]) != DS_FindSet(vSet[tIdx]) )
    {
      addEdge(mstV[fIdx], createEdge(mstV[fIdx], mstV[tIdx], currentE->wgt));
      addEdge(mstV[tIdx], createEdge(mstV[tIdx], mstV[fIdx], currentE->wgt));
      DS_UnionSet( vSet[fIdx], vSet[tIdx] );
    }
  }

  for(i = 0; i < g->vertexCnt; i++)
    DS_DestroySet(vSet[i]);

  free(mstV);
  free(vSet);
  
}
