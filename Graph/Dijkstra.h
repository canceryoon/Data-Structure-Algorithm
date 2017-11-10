#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include "PriorityQueue.h"

#define MAX_WGT 65536

void Dijkstra( myGraph *g, myVertex *startV, myGraph *mst );

#endif
