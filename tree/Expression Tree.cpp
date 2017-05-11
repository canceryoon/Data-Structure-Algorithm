#include "Expression Tree.h"

ETNode* ET_CreateNode( char _data )
{
    ETNode* nNode = (ETNode*)malloc(sizeof(ETNode));
    nNode->left = NULL;
    nNode->right = NULL;
    nNode->data = _data;
    return nNode;
}

void ET_DestoryNode( ETNode* dNode )
{
    free(dNode);
}

void ET_DestoryTree( ETNode* head )
{
    if(head)
    {   
        ET_DestoryTree(head->left);
        ET_DestoryTree(head->right);
        ET_DestoryNode(head);
    }
    return ;
}

void ET_PreorderPrintTree( ETNode* node )
{
    if(node)
    {
        std::cout << " " << node->data ;
        ET_PreorderPrintTree(node->left);
        ET_PreorderPrintTree(node->right);
    }
    return ;
}

void ET_InorderPrintTree( ETNode* node )
{
    if(node)
    {
        std::cout << "(" ;
        ET_InorderPrintTree(node->left);
        std::cout << node->data ;
        ET_InorderPrintTree(node->right);
        std::cout << ")" ;
    }
    return ;
}

void ET_PostorderPrintTree( ETNode* node )
{
    if(node)
    {
        ET_PostorderPrintTree(node->left);
        ET_PostorderPrintTree(node->right);
        std::cout << node->data ;
    }
    return ;
}

void ET_BuildExpressionTree( char* postFixNode, ETNode** node )
{
    int len  = std::strlen(postFixNode);
    char token = postFixNode[len-1];
    postFixNode[len-1] = '\0';

    switch(token)
    {
        case '+' : 
        case '-' : 
        case '*' : 
        case '/' :  (*node) = ET_CreateNode( token );
                    ET_BuildExpressionTree( postFixNode , &(*node)->right );
                    ET_BuildExpressionTree( postFixNode , &(*node)->left );
                    break;
        default  :  (*node) = ET_CreateNode( token );
                    break;
    }
}

double ET_Evaluate( ETNode* tree );
{
    char tmp[2];

    double left = 0;
    double right = 0;
    double ret = 0;

    if(tree)
    {
        switch( tree->data )
        {
            case '+' : 
            case '-' : 
            case '*' : 
            case '/' :  left = ET_Evaluate( tree->left );
                        right = ET_Evaluate( tree->right );
                        switch( tree->data )
                        {
                            case '+': ret = left + right; break;
                            case '-': ret = left - right; break;
                            case '*': ret = left * right; break;
                            case '/': ret = left / right; break;
                        }
                        break;
            default  :  memset(tmp, 0, sizeof(tmp));
                        tmp[0] = tree->data;
                        ret = std::atof(tmp);
                        break; 
        }
        return ret;
    }
    return 0;
}