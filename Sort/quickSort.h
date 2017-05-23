#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* arr, int l, int r)
{
    int len  = r;
    int f = l;
    int p = arr[f];
    l++;
    while(l <= r)
    {
        while(arr[l] <= p)
            l++;
        while(arr[r] > p)
            r--;

        //if(l < r) r--;  ?? why quick sort to this code?

        if(l < r) 
            swap(&arr[l], &arr[r]);
        else 
            break;
    }
    
    swap(&arr[f], &arr[r]);
    return r;   
}

void quicksort(int* arr, int l, int r)
{
    if( l < r )
    {
        int idx = partition(arr, l, r);
        quicksort(arr, l, idx-1);
        quicksort(arr, idx+1, r);
    }
}

#endif