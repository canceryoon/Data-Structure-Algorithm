#include "BinarySearchTree.h"

NODE* createNode(int _data)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = _data;
    node->right = NULL;
    node->left = NULL;

    return node;
}

void destroyNode(NODE* rnode)
{
    free(rnode);
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
        return searchNode(tree->left, target);
    else return searchNode(tree->right, target);

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
        return ;
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
    NODE* rm = NULL;

    if(tree == NULL)
        return NULL;

    if(tree->data > rdata)
        rm = removeNode(tree->left, tree, rdata);
    else if(tree->data < rdata)
        rm = removeNode(tree->right, tree, rdata);

    else
    {
        rm = tree;
        if(tree->left == NULL && tree->right == NULL)
        {
            if( parent && parent->left == tree )
                parent->left = NULL;
            else 
                parent->right = NULL;
        }
        else
        {
            if(tree->left != NULL && tree->right != NULL)
            {
                NODE* minNode = searchMinNode(tree->left);
                minNode = removeNode(tree, NULL, minNode->data);
                tree->data = minNode->data;
            }
            else
            {
                if(tree->left != NULL)
                {
                    if(parent->left == tree)
                        parent->left = tree->left;
                    else 
                        parent->right = tree->left;
                }
                else if(tree->right != NULL)
                {
                    if(parent->right == tree)
                        parent->right = tree->right;
                    else
                        parent->left = tree->right;
                }   
            }
        }


    }
    
    return rm;
}

void printNode(NODE* tree, int depth)
{
    if(tree == NULL)
        return ;

    printNode(tree->left, depth+1);

    for(unsigned int i = 0; i<depth; i++)
        std::cout << " ";

    std::cout << tree->data << std::endl;

    printNode(tree->right, depth+1);
}
