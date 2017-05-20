#ifndef INSERT_SORT_H
#define INSERT_SORT_H

#include <iostream>

void insertSort(int* arr, int len)
{
    int i,j;
    int var;
    for( i = 1; i < len; i++)
    {
        if(arr[i] < arr[i-1])
        {
            var = arr[i];
            for(j = 0; j < i; j++)
            {
                if(arr[j] > var)
                {
                    memmove(&arr[j+1], &arr[j], sizeof(arr[0])*(i-j));
                    arr[j] = var;
                    break;
                }
            }
        }
    }
}

#endif INSERT_SORT_H