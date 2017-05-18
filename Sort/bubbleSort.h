#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include<iostream>

void bubbleSort(int* data)
{
    int len = std::strlen(data);
    int tmp;
    int i,j;
    for(i=0; i < len-1; i++)
    {
         for(j=0; j < (len-i); j++)
        {
            if(data[j] > data[j+1])
            {
                tmp = data[j];
                data[j] = data[j+1];
                data[j] = tmp;
            }
        }
    }
}
#endif