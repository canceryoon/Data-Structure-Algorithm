#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include<iostream>
struct ETNode
{
    ETNode* left;
    ETNode* right;
    char data;
};

ETNode* ET_CreateNode( char ndata );
void ET_DestoryNode( ETNode* dNode );
void ET_DestoryTree( ETNode* head );

void EX_PreorderPrintTree( ETNode* node );
void ET_InorderPrintTree( ETNode* node );
void ET_PostorderPrintTree( ETNode* node );
void ET_BuildExpressionTree( char* postFixNode, ETNode** node );
double ET_Evaluate( ETNode* tree );

#endif