#include "TopologicalSort.h"
#include <iostream>

using namespace std;
int main()
{
  myGraph* g = createGraph();
  
  myVertex* v1 = createVertex(1);
  myVertex* v2 = createVertex(2);
  myVertex* v3 = createVertex(3);
  myVertex* v4 = createVertex(4);
  myVertex* v5 = createVertex(5);

  addVertex(g,v1);
  addVertex(g,v2);
  addVertex(g,v3);
  addVertex(g,v4);
  addVertex(g,v5);

  addEdge(v1, createEdge(v1,v2,5));
  addEdge(v1, createEdge(v1,v3,4));
  addEdge(v1, createEdge(v1,v4,2));
  addEdge(v1, createEdge(v1,v5,3));
 
  addEdge(v2, createEdge(v2,v3,1));
  addEdge(v2, createEdge(v2,v4,9));
  addEdge(v2, createEdge(v2,v5,11));

  addEdge(v3, createEdge(v3,v4,3));
  addEdge(v3, createEdge(v3,v5,3));

  addEdge(v4, createEdge(v4,v3,6));
  addEdge(v4, createEdge(v4,v2,7));
  addEdge(v4, createEdge(v4,v1,8));

  addEdge(v5, createEdge(v5,v2,1));
  addEdge(v5, createEdge(v5,v3,1));

  printGraph(g);

	cout << endl;
	Node* sortList = NULL;
	Node* currentNode = NULL;
	
	TopologicalSort(g->vertices, &sortList);
	currentNode = sortList;

	cout << "Topological sort : " << endl;
	while( currentNode != NULL )
	{
		cout << currentNode->val->data << " " ;		
		currentNode = currentNode->next;
	}
	cout << " "  << endl;
	
	destroyGraph(g);

  return 1;
}
