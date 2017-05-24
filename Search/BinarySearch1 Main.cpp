#include<iostream>
#include "BinarySearch1.h"

int main()
{
    int dataset[] = {1,4,3,9,7,0,5,8,2};
    int target = 2;
    int len = sizeof(dataset)/sizeof(dataset[0]);
    int ret;

    ret = binarysearch(&dataset[0], len, target);
    return ret;
}