#ifndef MST_H
#define MST_H

#include "Graph.h"
#include "PriorityQueue.h"

#include <iostream>
#include <stdlib.h>

#define MAX_WGT 2048

void prim( myGraph *g, myVertex *startV, myGraph *mst );

#endif
