#include "Graph.h"
#include "Dijkstra.h"

#include <stdio.h>

using namespace std;
int main()
{
  myGraph *g = createGraph();
  myGraph *primMST = createGraph();
  myGraph *kruskalMST = createGraph();

  myVertex *v1 = createVertex(1);
  myVertex *v2 = createVertex(2);
  myVertex *v3 = createVertex(3);
  myVertex *v4 = createVertex(4);
  myVertex *v5 = createVertex(5);
  myVertex *v6 = createVertex(6);
  myVertex *v7 = createVertex(7);
  myVertex *v8 = createVertex(8);
  myVertex *v9 = createVertex(9);

  addVertex(g, v1);
  addVertex(g, v2);
  addVertex(g, v3);
  addVertex(g, v4);
  addVertex(g, v5);
  addVertex(g, v6);
  addVertex(g, v7);
  addVertex(g, v8);
  addVertex(g, v9);

  addEdge(v1, createEdge(v1, v2, 35)); 
  addEdge(v1, createEdge(v1, v5, 247)); 

  addEdge(v2, createEdge(v2, v1, 35)); 
  addEdge(v2, createEdge(v2, v3, 126)); 
  addEdge(v2, createEdge(v2, v6, 150)); 
  
  addEdge(v3, createEdge(v3, v2, 126)); 
  addEdge(v3, createEdge(v3, v4, 117)); 
  addEdge(v3, createEdge(v3, v6, 162)); 
  addEdge(v3, createEdge(v3, v7, 220)); 
	
  addEdge(v4, createEdge(v4, v3, 117)); 
	
  addEdge(v5, createEdge(v5, v1, 247)); 
  addEdge(v5, createEdge(v5, v6, 82)); 
  addEdge(v5, createEdge(v5, v8, 98)); 
  
  addEdge(v6, createEdge(v6, v2, 150)); 
  addEdge(v6, createEdge(v6, v3, 162)); 
  addEdge(v6, createEdge(v6, v5, 82)); 
  addEdge(v6, createEdge(v6, v7, 154)); 
  addEdge(v6, createEdge(v6, v8, 120)); 
  
  addEdge(v7, createEdge(v7, v3, 220)); 
  addEdge(v7, createEdge(v7, v6, 154)); 
  addEdge(v7, createEdge(v7, v9, 106)); 
  
  addEdge(v8, createEdge(v8, v5, 98)); 
  addEdge(v8, createEdge(v8, v6, 120)); 
  
  addEdge(v9, createEdge(v9, v7, 106)); 
 
  cout << "Print Graph" << endl;
  printGraph(g);

  puts("");
  puts("");

	puts("Dijkstra");
	Dijkstra(g, v2, primMST);
	printGraph(primMST);

  destroyGraph(g);
  destroyGraph(primMST);
  destroyGraph(kruskalMST);

  return 1;
}
