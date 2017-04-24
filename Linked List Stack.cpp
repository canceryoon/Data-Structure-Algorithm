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

int main()
{
    int x;
    char* _data;
    
    LLStack* mySt = NULL;
    LLS_CreateStack(&mySt);

    do
    {
        std::cout << "0. End   1. Push   2. Pop   3. Top   4. Size   5. Print" << std::endl;
        std::cin >> x;
        switch(x)
        {
            case 1: std::cout << "Input string data: " << std::endl;
                    std::cin >> _data;
                    //std::cout << _data << std::endl;
                    LLS_Push( mySt, LLS_CreateNode(_data)); break;
            case 2: std::cout << "Pop data: " << ((LLS_Pop(mySt) != NULL)?LLS_Pop(mySt)->data : "No create Stack.") << std::endl; break;
            case 3: std::cout << "Top data: " << ((LLS_Top(mySt) != NULL)?LLS_Pop(mySt)->data : "No create Stack.")  << std::endl; break;
            case 4: std::cout << "Stack Size: " << mySt->nodeCnt << std::endl; break;
            case 5: LLS_Print(mySt); break;
        }
    }while( x != 0 );

    LLS_DestroyStack(mySt);
    return 1;
}