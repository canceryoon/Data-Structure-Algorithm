#include<iostream>
struct LCRSNode
{
    char data;
    LCRSNode* leftChiled;
    LCRSNode* rightSibling;
};

LCRSNode* LCRS_CreateNode(char _data)
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
    std::cout << root->data << std::endl;

    if( root->leftChiled != NULL ) LCRS_PrintTree(root->leftChiled, depth+1);
    if( root->rightSibling != NULL ) LCRS_PrintTree(root->rightSibling, depth);
}

int main()
{
    LCRSNode* head = LCRS_CreateNode('A');

    LCRSNode* a = LCRS_CreateNode('b');
    LCRSNode* b = LCRS_CreateNode('c');
    LCRSNode* c = LCRS_CreateNode('d');
    LCRSNode* d = LCRS_CreateNode('e');
    LCRSNode* e = LCRS_CreateNode('f');
    LCRSNode* f = LCRS_CreateNode('g');
    LCRSNode* g = LCRS_CreateNode('h');
    LCRSNode* h = LCRS_CreateNode('i');

    LCRS_AddChildNode(head, a);
     LCRS_AddChildNode(a, b);
     LCRS_AddChildNode(a, c);
      LCRS_AddChildNode(b, d);
      LCRS_AddChildNode(c, e);
      LCRS_AddChildNode(c, f);
       LCRS_AddChildNode(f, g);
        LCRS_AddChildNode(g, h);
    
    LCRS_PrintTree(head, 0); // 0 is print depth
    LCRS_Destorytree(head);
    return 1;   
}