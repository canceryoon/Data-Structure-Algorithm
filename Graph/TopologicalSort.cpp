#include "TopologicalSort.h"

using namespace std;

void TopologicalSort( myVertex* v, Node** list)
{
	while( v != NULL && v->visited != Visited )
	{
		TS_DFS(v, list);
		v = v->next;
	}
}

void TS_DFS( myVertex* v, Node** list)
{
	Node* newHead = NULL;
	myEdge* e = NULL;
	
	v->visited = Visited;
	e = v->adjacencyList;
	
	while( e != NULL )
	{
		if( e->to != NULL && e->to->visited != Visited )
			TS_DFS(e->to, list);
			
		e = e->next;
	}
	
	newHead = (Node*)malloc(sizeof(Node));
	newHead->val = v;
	newHead->next = NULL;
	insertNHead(list, newHead);
}
