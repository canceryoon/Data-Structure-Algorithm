#include<iostream>
#include "Circle Double Linked List.h"

int main()
{
    Node* myNode = new Node(4);
    CDList* myList = new CDList(myNode);

    myList->select();

    return 1;
}