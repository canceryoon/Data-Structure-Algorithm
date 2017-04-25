#ifndef LLSTACK_H
#define LLSTACK_H

#include<iostream>

typedef struct tagNode{
    char* data;
    tagNode* next;
} Node;

typedef struct LinkedListStack{
    int nodeCnt;
    Node* list;
    Node* top;
}LLStack;

Node* LLS_CreateNode( char* data )
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = (char*)malloc(sizeof(data)+1);
    strcpy(tmp->data, data);
    tmp->next = NULL;

    return tmp;
}

void LLS_DestroyNode( Node* node )
{
    free(node->data);
    free(node);
}

void LLS_Push( LLStack* st, Node* node )
{
    if( st->list != NULL )
    {
        Node* old = st->list;
        while( old->next != NULL) old = old->next;
        old->next = node;
    }
    else
    {
        st->list = node;        
    }
    st->nodeCnt++;
    st->top = node;
}

Node* LLS_Pop( LLStack* st)
{
    if(st->nodeCnt == 0) return NULL;
    Node* top = st->top;

    if( top != st->list )
    {
        Node* newTop = st->list;
        while( newTop->next != st->top ) newTop = newTop->next;
        st->top = newTop;
        newTop->next = NULL;
    }
    else
    {
        st->list = NULL;
        st->top = NULL;
    }
    st->nodeCnt--;
    return top;
}

void LLS_CreateStack( LLStack** st)
{
    (*st) = (LLStack*)malloc(sizeof(LLStack));
    (*st)->nodeCnt = 0;
    (*st)->list = NULL;
    (*st)->top = NULL;
}

void LLS_DestroyStack( LLStack* st)
{
    while(st->list != NULL)
    {
        Node* tmp = LLS_Pop( st );
        LLS_DestroyNode(tmp);
    }
    free(st);
}

void LLS_Print( LLStack *st)
{
    int offset = 1;
    if(st->nodeCnt == 0){ std::cout << "No create Stack." << std::endl; return ;}
    Node* tmp = st->list;
    while( tmp != st->top)
    {
        std::cout << offset++ << " stack data : " << tmp->data << std::endl;
        tmp = tmp->next;
    }
    std::cout << offset++ << " stack data : " << tmp->data << std::endl;
}

Node* LLS_Top( LLStack* st )
{
    if(st->nodeCnt == 0) return NULL;
    return st->top;
} 
#endif
