#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = *a;
}

int partition(int* arr, int l, int r)
{
    int f = l++;
    int p = arr[f];

    while(l <= r)
    {
        while(arr[l++] <= p);
        while(arr[r--] > p);

        if(l < r) r--;

        if(l < r) swap(&arr[l], &arr[r]);
        else break;
    }
    
    swap(&arr[f], &arr[r]);
    return r;   
}

void quicksort(int* arr, int l, int r)
{
    if( l < r )
    {
        int idx = partition(arr, l, r);
        std::cout << "after partition " << idx << std::endl;
        quicksort(arr, l, idx-1);
        quicksort(arr, idx+1, r);
    }
}

#endif