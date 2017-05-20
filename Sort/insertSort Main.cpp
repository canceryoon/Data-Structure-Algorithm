#include <iostream>
#include "insertSort.h"

int main()
{
    int arr[] = {4,1,5,7,3,6,0,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    insertSort(&arr[0], len);
    for(int i = 0 ; i < len; i++ )
        std::cout << arr[i] << " ";
}