#include<iostream>
#include"DisjointSet.h"

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;

    DisjointSet* aSet = DS_MakeSet(&a);
    DisjointSet* bSet = DS_MakeSet(&b);
    DisjointSet* cSet = DS_MakeSet(&c);
    DisjointSet* dSet = DS_MakeSet(&d);

    std::cout << "aSet == bSet : " << (DS_FindSet(aSet) == DS_FindSet(bSet)) << std::endl;
    DS_UnionSet(cSet, dSet);
    std::cout << "cSet == dSet : " << (DS_FindSet(cSet) == DS_FindSet(dSet)) << std::endl;

    DS_DestroySet(aSet);
    DS_DestroySet(bSet);
    DS_DestroySet(cSet);
    DS_DestroySet(dSet);
    return 1;
}