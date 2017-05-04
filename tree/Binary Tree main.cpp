#include<iostream>
#include "Binary Tree.h"

int main()
{
    Node* _head = new Node('A');
    Node* ihead1 = new Node('B');
    Node* ihead2 = new Node('C');
    Node* ihead3 = new Node('D');
    Node* ihead4 = new Node('E');
    Node* ihead5 = new Node('F');
    Tree* head = new Tree(_head);
    
    head->insertTree(ihead1);
    head->insertTree(ihead2);
    head->insertTree(ihead3);
    head->insertTree(ihead4);
    head->insertTree(ihead5);
    std::cout << "Print Tree Func." << std::endl;
    head->printTree(0);

    free(_head);
    free(ihead1);
    free(ihead2);
    free(ihead3);
    free(ihead4);
    free(ihead5);
    free(head);
}