#include <iostream>
#include "bubbleSort.h"

int main()
{
    int arr[] = {9,42,5,6,8,1,5,7};
    bubbleSort(arr, sizeof(arr)/sizeof(int));
    for(int i = 0 ; i < sizeof(arr)/sizeof(int); i++ )
        std::cout << arr[i] << " ";
}