#include<iostream>

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

struct DisjointSet{
    DisjointSet* parent;
    void* data;
};

void DS_UnionSet( DisjointSet* set1, DisjointSet* set2 );
DisjointSet* DS_FindSet( DisjointSet* set );
DisjointSet* DS_MakeSet( void* newData );
void DS_DestroySet( DisjointSet* set );

#endif