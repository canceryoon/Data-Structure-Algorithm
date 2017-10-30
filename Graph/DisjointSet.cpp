#include "DisjointSet.h"

void DS_UnionSet( DisjointSet* set1, DisjointSet* set2 )
{
    set2 = DS_FindSet(set2);
    set1->parent = set2;
}

DisjointSet* DS_FindSet( DisjointSet* set )
{
    while( set->parent != NULL ) set = set->parent;
    return set;
}

DisjointSet* DS_MakeSet( void* ndata )
{
    DisjointSet* node = (DisjointSet*)malloc(sizeof(DisjointSet));
    node->data = ndata;
    node->parent = NULL;
    return node;
}

void DS_DestroySet( DisjointSet* set )
{
    free(set);
}