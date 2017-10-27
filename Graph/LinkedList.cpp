#include "LinkedList.h"
using namespace std;

void insert(node* start, myVertex* x)
{
    node* t = start;
    if( !start )
    {
        node* _next = (node*)malloc(sizeof(node));
				_next->val = (myVertex*)malloc(sizeof(myVertex));
				memcpy(_next->val, x, sizeof(myVertex));
        _next->next = NULL;
        start = _next;
    }
    else
    {
        while(t->next)
        {
            t = t->next;
        }
        node* _next = (node*)malloc(sizeof(node));
				_next->val = (myVertex*)malloc(sizeof(myVertex));
				memcpy(_next->val, x, sizeof(myVertex));
        _next->next = NULL;
        t->next = _next;
    }
}

void select(node* start)
{
    int count = 1;
    if(!start) cout << "No data" << endl;
    node* t = start;
    while(t)
    {
        cout << count << " node : " << t->val->data << endl;
        count++;
        t = t->next;
    }
}

void search(node* start, myVertex* x)
{
    if(!start) cout << "No Node" << endl;
    int count = 1;
    int flag = 0;
    node* t = start;
    while(t)
    {   
        if(memcmp(t->val, x, sizeof(myVertex)) == 0)
        {
            cout << count << " node has " << t->val->data << endl;
            flag = SEARCH_TRUE;
        }
        count++;
        t = t->next;
    }
    if( flag ^ SEARCH_TRUE ) cout << "No data in node: " << x << endl;
}

void remove(node* start, myVertex* x)
{
    if(!start) cout << "No Node" << endl;
    node* t = start;
    node* p;
    int flag = 0;
    while(t)
    {   
        if(memcmp(t->val, x, sizeof(myVertex)) == 0)
        {
            p->next = t->next;
            free(t);
            t = p->next;
            flag = DELETE_TRUE;
            continue;
        }
        p=t;
        t=t->next;
    }
    if( flag ^ DELETE_TRUE ) cout << "No data in node: " << x << endl;   
}

void update(node* start, myVertex* _x, myVertex* x)
{
    if(!start) cout << "No Node" << endl;
    int count = 1;
    int flag = 0;
    node* t = start;
    while(t)
    {   
        if(memcmp(t->val, _x, sizeof(myVertex)) == 0)
        {
						memcpy(t->val, x, sizeof(myVertex));
            flag = UPDATE_TRUE;
            return ;
        }
        count++;
        t = t->next;
    }
    if( flag ^ UPDATE_TRUE ) cout << "No data in node: " << _x << endl;   
}
