#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include<iostream>

void bubbleSort(int data[], int _len)
{
    int len = _len;
    int tmp;
    int i,j;
    for(i=0; i < len-1; i++)
    {
         for(j=0; j < (len-(i+1)); j++)
        {
            if(data[j] > data[j+1])
            {
                tmp = data[j+1];
                data[j+1] = data[j];
                data[j] = tmp;
            }
        }
    }
}
#endif