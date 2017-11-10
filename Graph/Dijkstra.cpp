#include "Dijkstra.h"

void Dijkstra(myGraph *g, myVertex *startV, myGraph *mst)
{
	unsigned int i = 0;
	NODE startNode = { 0, startV };
	HEAP PQ(50);

	myVertex *curV = NULL;
	myEdge *curE = NULL;
	int *wgt = (int*)malloc(sizeof(int) * g->vertexCnt);
	myVertex **shortestV = (myVertex**)malloc(sizeof(myVertex*) * g->vertexCnt);
	myVertex **f = (myVertex**)malloc(sizeof(myVertex*)*g->vertexCnt);
	myVertex **p = (myVertex**)malloc(sizeof(myVertex*)*g->vertexCnt);

	curV = g->vertices;
	while( curV != NULL )
	{
		myVertex *nV = createVertex( curV->data );	
		addVertex( mst, nV );
		f[i] = NULL;
		p[i] = NULL;
		shortestV[i] = nV;
		wgt[i] = MAX_WGT;
		curV = curV->next;
		i++;
	}

	PQ.enQueue(startNode);
	wgt[startV->idx] = 0;
	while( !PQ.isEmpty() )
	{
		NODE pop;
		PQ.deQueue(&pop);
		curV = (myVertex*)pop._data;
		f[curV->idx] = curV;
		curE = curV->adjacencyList;
		while( curE != NULL )
		{
			myVertex *to = curE->to;
			if( f[to->idx] == NULL && (wgt[curV->idx] + curE->wgt) < wgt[to->idx] )
			{
				NODE nNode = { curE->wgt, to };
				PQ.enQueue(nNode);
				p[to->idx] = curE->from;
				wgt[to->idx] = wgt[curV->idx] + curE->wgt;		
			}
			curE = curE->next;
		}
	}

	for(i = 0; i < g->vertexCnt; i++ )
	{
		int fIdx, tIdx;
		if( p[i] == NULL )
				continue;

		fIdx = p[i]->idx;
		tIdx = i;
		addEdge( shortestV[fIdx], createEdge(shortestV[fIdx], shortestV[tIdx], wgt[i]));
	}

	free(f);
	free(p);
	free(shortestV);
	free(wgt);
}
