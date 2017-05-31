#include "BinarySearchTree.h"

int main(void)
{

    NODE* tree = createNode(25);
    NODE* node = NULL;

    insertNode(tree, createNode(22));
    insertNode(tree, createNode(32));
    insertNode(tree, createNode(52));
    insertNode(tree, createNode(2));
    insertNode(tree, createNode(56));
    insertNode(tree, createNode(5));
    insertNode(tree, createNode(0));
    insertNode(tree, createNode(13));
    
    printNode(tree, 0);

    std::cout << "Remove 32" << std::endl;
    node = removeNode(tree, NULL, 32);
    destroyNode(node);

    printNode(tree, 0);

    std::cout << "Insert 111" << std::endl;
    insertNode(tree, createNode(111));
   
    printNode(tree, 0);

    destroyTree(tree);
    
    return 1;
}