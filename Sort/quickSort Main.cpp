#include <iostream>
#include "quickSort.h"

int main()
{
    int arr[] = {4,1,5,7,3,6,0,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    quicksort(&arr[0], 0, len-1);
    for(int i = 0 ; i < len; i++ )
        std::cout << arr[i] << " ";
}