#include<iostream>
#include "BinarySearch1.h"

inline static int compareFunc(const void* elem1, const void* elem2)
{
    int* e1 = (int*)elem1;
    int* e2 = (int*)elem2;
    if( *e1 > *e2 ) return 1;
    else if( *e1 < * e2 ) return -1;
    return 0;
}

int main()
{
    int dataset[] = {1,4,3,9,7,0,5,8,2};
    int target ;
    int len = sizeof(dataset)/sizeof(dataset[0]);
    int ret;
    std::cout << "Enter the search num: ";
    std::cin >> target;

    qsort( (void*)dataset, len, sizeof(int), compareFunc);
    ret = binarysearch(&dataset[0], len, target);
    
    if( ret == target )
        std::cout << "Found the " << ret << std::endl;
    else std::cout << "Data Set does not has " << ret << std::endl;
    
    return ret;
}