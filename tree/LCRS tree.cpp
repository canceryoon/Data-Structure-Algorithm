#include<iostream>
struct LCRSNode
{
    int data;
    LCRSNode* leftChiled;
    LCRSNode* rightSibling;
}

LCRSNode* LCRS_CreateNode(int _data)
{
    LCRSNode* newNode = (LCRSNode*)malloc(sizeof(LCRSNode));
    newNode->data = _data;
    newNode->leftChiled = NULL;
    newNode->rightSibling = NULL;
    return newNode;
}

void LCRS_DestoryNode(LCRSNode* deNode)
{
    free(deNode);
}

void LCRS_Destorytree(LCRSNode* root)
{
    if( root->rightSibling != NULL ) LCRS_Destorytree(root->rightSibling);
    if( root->leftChiled != NULL ) LCRS_Destorytree(root->leftChiled);

    root->leftChiled = NULL;
    root->rightSibling = NULL;

    free(root);
}

void LCRS_AddChildNode(LCRSNode* p, LCRSNode* c)
{
    if( p->leftChiled == NULL )
    {
        p->leftChiled = c;
    }
    else
    {
        LCRSNode* tmp = p->leftChiled;
        while(tmp->rightSibling != NULL) tmp = tmp->rightSibling;
        tmp->rightSibling = c;
    }
}

void LCRS_PrintTree(LCRSNode* root, int depth)
{
    for(int i = 0; i < depth; i++) std::cout << " " ;
    std::cout << root->data << endl;

    if( root->leftChiled != NULL ) LCRS_PrintTree(root->leftChiled, depth+1);
    if( root->rightSibling != NULL ) LCRS_PrintTree(root->rightSibling, depth);
}