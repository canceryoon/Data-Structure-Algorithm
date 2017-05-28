#include "BinarySearchTree.h"

NODE* createNode(int _data)
{
    NODE* node = (NODE*)malloc(sizeof(NODE());
    node->data = _data;
    node->right = NULL;
    node->left = NULL;

    return node;
}

void destroyNode(NODE* rnode)
{
    free(node);
}

void destroyTree(NODE* tree)
{
    if(tree->left != NULL)
        destroyTree(tree->left);
    
    if(tree->right != NULL)
        destroyTree(tree->right);
    
    tree->left = NULL;
    tree->right = NULL;
    destroyNode(tree);
}

NODE* searchNode(NODE* tree, int target)
{
    if(tree == NULL)
        return NULL;

    if(tree->data == target)
        return tree;
    
    if(tree->data < target)
        return searchNode(tree->left);
    else return searchNode(tree->right);

    std::cout << "No data found: " << target << std::endl;
    return NULL;
}

NODE* searchMinNode(NODE* tree)
{
    if(tree == NULL)
    {
        std::cout << "Input Tree is NULL" << std::endl;
        return NULL;
    }

    if(tree->left != NULL )
        return searchMinNode(tree->left);
        
    return tree;
}

void insertNode(NODE* tree, NODE* child)
{
    if(tree == NULL)
    {
        std::cout << "Input Tree is NULL" << std::endl;
        return NULL;
    }

    if(tree->data > child->data)
    {
        if(tree->left)
            insertNode(tree->left, child);
        else
            tree->left = child; 
    }
    else if(tree->data < child->data)
    {
        if(tree->right)
            insertNode(tree->right, child);
        else
            tree->right = child; 
    }
}

NODE* removeNode(NODE* tree, NODE* parent, int rdata)
{
    
    return tree;
}