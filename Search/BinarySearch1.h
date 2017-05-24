#ifndef BINARY_SEARCH_1_H
#define BINARY_SEARCH_1_H

int binarysearch(int* arr, int size, int target)
{
    int l,r,m;
    
    l = 0;
    r = size - 1;
    while(l <= r)
    {
        m = (l + r) / 2;
        if( arr[m] == target )
            return arr[m];
        
        else if( arr[m] > target )
            r = m - 1;
        else
            l = m + 1;
    }

    return -1;
}

#endif