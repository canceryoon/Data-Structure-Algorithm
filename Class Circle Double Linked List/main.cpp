#include<iostream>
#include "Circle Double Linked List.h"

int main()
{
    int x, offset, _val;
    std::cout << "Input first node data: ";
    std::cin >> x;
    Node* myNode = new Node(x);
    Node* tmp;
    CDList* myList = new CDList(myNode);

    do
    {
        std::cout << "0. End" << std::endl << "1. Insert" << std::endl << "2. insertOffset" << std::endl << "3. select " << std::endl << "4. selectOffset" << std::endl << "5. selectData" << std::endl << "6. deleteOffset" << std::endl << "7. deleteData" << std::endl << "8. Nodes Num" << std::endl;
        std::cin >> x;
        switch(x)
        {
            case 0: break;
            case 1: std::cout << "Input Num";
                    std::cin >> _val;
                    tmp = new Node(_val);
                    myList->insert(tmp);
                    tmp = NULL;
                    break;
            case 2: std::cout << "Input offset";
                    std::cin >> offset;
                    std::cout << "Input Num";
                    std::cin >> _val;
                    tmp = new Node(_val);
                    myList->insertOffset(offset, tmp);
                    break;
            case 3: myList->select(); break;
            case 4: std::cout << "Input offset";
                    std::cin >> offset;
                    myList->selectOffset(offset);
                    break;
            case 5: std::cout << "Input Num";
                    std::cin >> _val;
                    myList->selectData(_val);
                    break;
            case 6: std::cout << "Input offset";
                    std::cin >> offset;
                    myList->deleteOffset(offset);
                    break;
            case 7: std::cout << "Input Num";
                    std::cin >> _val;
                    myList->deleteData(_val);
                    break;
            case 8: std::cout << "Node num: " << myList->getNodeCnt() << std::endl;
                    break;
            default: std::cout << "Input 0~8 Num." << std::endl; break;
        }
    }while(x != 0);

    // myList->deleteAllNode();
    delete myList;

    return 1;
}