#include "ReadBlackTree.h"

RBNode* createRBNode(int _data)
{
    RBNode* rbnode = (RBNode*)malloc(sizeof(RBNode));

    rbnode->data = _data;
    rbnode->parent = Nil;
    rbnode->left = Nil;
    rbnode->right = Nil;
    rbnode->color = BLACK;

    return rbnode;
}

void destroyRBNode(RBNode* rnode)
{
    rnode->left = Nil;
    rnode->right = Nil;
    rnode->parent = Nil;
    
    free(rnode);
}

void destroyRBTree(RBNode* tree)
{
    if(tree == Nil) return;

    if(tree->left != Nil)
        destroyRBTree(tree->left);
    
    if(tree->right != Nil)
        destroyRBTree(tree->right);

    destroyRBNode(tree);
}

RBNode* searchRBNode(RBNode* tree, int target)
{
    if(tree == Nil)
        return NULL;

    if(tree->data == target)
        return tree;
    
    if(tree->data < target)
        return searchNode(tree->right, target);
    else return searchNode(tree->left, target);

    std::cout << "No data found: " << target << std::endl;
    return NULL;
}

RBNode* searchMinRBNode(RBNode* tree)
{
    if(tree == Nil)
        return NULL;

    if(tree->left != Nil)
        return searchMinRBNode(tree->left);

    return tree;
}

void rotateRight(RBNode** root, RBNode* parent)
{
    RBNode* leftchild = parent->left;
    parent->left = leftchild->right;

    if(leftchild->right != Nil)
        leftchild->right->parent = parent;

    leftchild->parent = parent->parent;
    
    if(parent->parent == NULL)
        (*root) = leftchild;
    else
    {
        if(parent->parent->left == parent)
            parent->parent->left = leftchild;
        else
            parent->parent->right = leftchild;
    }

    leftchild->right = parent;
    parent->parent = leftchild;
}

void rotateLeft(RBNode** root, RBNode* parent)
{
    RBNode* rightchild = parent->right;
    parent->right = rightchild->left;

    if(rightchild->left != Nil)
        rightchild->left->parent = parent;

    rightchild->parent = parent->parent;

    if(parent->parent == Nil)
        (*root) = rightchild;
    else 
        if(parent->parent->left == parent)
            parent->parent->left = rightchild;
        else
            parent->parent->right = rightchild;

    rightchild->left = parent;
    parent->parent = rightchild
}