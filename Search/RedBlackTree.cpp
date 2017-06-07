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

/**
* 1. Find node seat.
* 2. Set Color default: Red.
* 3. Check and repair Red Black Tree Rules.
**/
void insertNode(RBNode** tree, RBNode* nNode)
{
    insertNodeHelper(tree, nNode);
    
    nNode->color = RED;
    nNdoe->right = Nil;
    nNdoe->left = Nil;

    rebuildAfterInsert(tree, nNode);
}

// compare Insert node data and tree datas, find a node seat.
void insertNodeHelper(RBNode** tree, RBNode* nNode)
{
    if((*tree) == NULL)
        (*tree) = nNode;
    
    if((*tree)->data < nNode->data)
    {
        if((*tree)->right != Nil)
        {
            (*tree)->right = nNode;
            nNode->parent = (*tree);
        }
        else
            insertNodeHelper(&(*tree)->right, nNode);
    }
    else
    {
        if((*tree)->left != Nil)
        {
            (*tree)->left = nNode;
            nNode->parent = (*tree);
        }
        else
            insertNodeHelper(&(*tree)->left, nNode);
    }
}

// Check and Repair Red Black Tree Rules.
void rebuildAfterInsert(NODE** tree, NODE* x)
{

    while( x != (*tree) && x->parent->color == RED )
    {
        if( x->parent == x->parent->parent->left )
        {
            NODE* uncle = x->parent->parent->right;
            
            if( uncle->color == RED )
            {
                x->parent->color = BLACK;
                uncle->color = BLACK;
                
                x->parent->parent->color = RED;
                x = x->parent->parent;
            }
            else
            {
                if( x == x->parent->right )
                {
                    x = x->parent;
                    RBT_rotateLeft(tree, x);
                }
                
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                
                RBT_rotateRight(tree, x->parent->parent);

            }
        }
        else
        {
            NODE* uncle = x->parent->parent->left;
            
            if( uncle->color == RED )
            {
                uncle->color = BLACK;

                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            }
            else
            {
                if( x == x->parent->left )
                {
                    x = x->parent;
                    RBT_rotateRight(tree, x);
                }

                x->parent->color = BLACK;
                x->parent->parent->color = RED;

                RBT_rotateLeft(tree, x->parent->parent);
            }
        }
    }

    (*tree)->color = BLACK;
}

RBNode* removeNode(RBNode** tree, int data)
{
    NODE* removed = NULL;
    NODE* successor = NULL;
    NODE* target = searchRBNode( (*root), data );

    if(target == NULL)
        return NULL;
    
    if( target->left == Nil || target->right == Nil )
        removed = target;
    else
    {
        removed = searchMinRBNode( target->right );
        target->data = removed->data;
    }

    if(removed->left != Nil)
        successor = removed->left;
    else
        successor = removed->right;

    successor->parent = removed->parent;

    if(removed->parent == NULL)
        (*root) = successor;
    else
    {
        if(removed == removed->parent->left)
            removed->parent->left = successor;
        else
            removed->parent->right = successor;
    }

    if(removed->color == BLACK)
        RBT_rebuildAfterRemove(root, successor);
    
    return removed;
}

void rebuildAfterRemove(RBNode** tree, RBNode* x)
{
    NODE* sibling = NULL;
    
    while( x->parent != NULL && x->color == BLACK )
    {
        if(x == x->parent->left)
        {
            sibling = x->parent->right;

            if(sibling->color == RED)
            {
                sibling->color = BLACK;
                x->parent->color = RED;
                RBT_rotateLeft(root, x->parent);
                sibling = x->parent->right;
            }
            else
            {
                if(sibling->left->color == BLACK && sibling->right->color == BLACK)
                {
                    sibling->color = RED;
                    x = x->parent;
                }
                else
                {
                    if(sibling->left->color == RED)
                    {
                        sibling->left->color = BLACK;
                        sibling->color = RED;

                        RBT_rotateRight(root,sibling);
                        sibling = x->parent->right;
                    }

                    sibling->color = x->parent->color;
                    x->parent->color = BLACK;
                    sibling->right->color = BLACK;
                    RBT_rotateLeft(root, x->parent);
                    x = (*root);

                }
            }
        }
        else
        {
            sibling = x->parent->left;
            if(sibling->color == RED)
            {
                sibling->color = BLACK;
                x->parent->color = RED;
                RBT_rotateRight(root, x->parent);
                sibling = x->parent->left;
            }
            else
            {
                if(sibling->right->color == BLACK && sibling->left->color == BLACK)
                {
                    sibling->color = RED;
                    x = x->parent;
                }
                else
                {
                    if(sibling->right->color == RED)
                    {
                        sibling->right->color = BLACK;
                        sibling->color = RED;
                        RBT_rotateLeft(root, sibling);
                        sibling = x->parent->left;
                    }

                    sibling->color = x->parent->color;
                    x->parent->color = BLACK;
                    sibling->left->color = BLACK;
                    RBT_rotateRight(root, x->parent);
                    x = (*root);

                }
            }
        }
    }
    x->color = BLACK;
}