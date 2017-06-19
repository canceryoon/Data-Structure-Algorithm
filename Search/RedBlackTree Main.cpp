#include<iostream>
#include"RedBlackTree.h"

RBNode* Nil;

int main()
{
    RBNode* tree = NULL;
    RBNode* node = NULL;

    Nil = createRBNode(0);
    Nil->color = BLACK;

    while(1)
    {
        int cmd = 0;
        int param = 0;
        char buffer[10];
        
        std::cout << "Enter number" << std::endl;
        std::cout << " 1. create node  2. remove node  3. search node   4. print tree  5. exit" << std::endl;
        std::cin >> cmd;

        if(cmd < 1 || cmd > 5)
        {
            std::cout << "Invaild command number." << std::endl;
            continue;
        }
        else if(cmd == 4)
        {
            printTree(tree, 0, 0);
            std::cout << " " << std::endl;
            continue;
        }
        else if(cmd == 5)
            break;

        std::cout << "EnterParamter (1~200) :\n" << std::endl;
        std::cin >> param ;
        
        if( param < 1 || param > 200 )
        {
            std::cout << "Invaild parameter" << std::endl;
            continue;
        }

        switch(cmd)
        {
            case 1: insertNode(&tree, createRBNode(param));       
                    break;

            case 2: node = removeNode(&tree,param);
                    if( node == NULL )
                        std::cout << "Not found to delete" << param << std::endl;
                    else
                        destroyRBNode(node);
                    break;

            case 3: node = searchRBNode(tree, param);
                    if( node == NULL )
                        std::cout << "Not found node: " << param << std::endl;
                    else
                        std::cout << "Found Node: " << node->data << " color: " << ((node->color==RED)?"RED":"BLACK") << std::endl;
                    break;
        }
    }

    destroyRBTree(tree);
}