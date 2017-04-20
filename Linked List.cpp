#include<iostream>
#define SEARCH_TRUE 0x1
#define DELETE_TRUE 0x2
#define UPDATE_TRUE 0x3
using namespace std;
struct node
{
    int val;
    node* next;
};
typedef struct node node;
node* start;

void insert(int x)
{
    node* t = start;
    if( !start )
    {
        node* _next = new node;
        _next->val = x;
        _next->next = NULL;
        start = _next;
    }
    else
    {
        while(t->next)
        {
            t = t->next;
        }
        node* _next = new node;
        _next->val = x;
        _next->next = NULL;
        t->next = _next;
    }
}

void select()
{
    int count = 1;
    if(!start) cout << "No data" << endl;
    node* t = start;
    while(t)
    {
        cout << count << " node : " << t->val << endl;
        count++;
        t = t->next;
    }
}

void search(int x)
{
    if(!start) cout << "No Node" << endl;
    int count = 1;
    int flag = 0;
    node* t = start;
    while(t)
    {   
        if(t->val == x)
        {
            cout << count << " node has " << t->val << endl;
            flag = SEARCH_TRUE;
        }
        count++;
        t = t->next;
    }
    if( flag ^ SEARCH_TRUE ) cout << "No data in node: " << x << endl;
}

void remove(int x)
{
    if(!start) cout << "No Node" << endl;
    node* t = start;
    node* p;
    int flag = 0;
    while(t)
    {   
        if(t->val == x)
        {
            p->next = t->next;
            t = NULL;
            delete t;
            t = p->next;
            flag = DELETE_TRUE;
            continue;
        }
        p=t;
        t=t->next;
    }
    if( flag ^ DELETE_TRUE ) cout << "No data in node: " << x << endl;   
}

void update(int _x, int x)
{
    if(!start) cout << "No Node" << endl;
    int count = 1;
    int flag = 0;
    node* t = start;
    while(t)
    {   
        if(t->val == _x)
        {
            t->val = x;
            flag = UPDATE_TRUE;
            return ;
        }
        count++;
        t = t->next;
    }
    if( flag ^ UPDATE_TRUE ) cout << "No data in node: " << _x << endl;   
}

int main()
{
    int n,x,_x;
    do{
        cout << "1. insert" << endl << "2. select" << endl << "3. Search" << endl << "4. update" << endl << "5. delete" << endl << "6. End" << endl;
        cin >> n;
        switch(n)
        {
            case 1: 
                cout << "Insert Num" << endl; 
                cin >> x;
                insert(x);
                break;
            case 2: 
                cout << "Select Num" << endl; 
                select();
                break;
            case 3: 
                cout << "Search Num" << endl; 
                cin >> x;
                search(x);
                break;
            case 4: 
                cout << "Update A Num to B Num" << endl; 
                cin >> _x;
                cin >> x;
                update(_x, x); 
                break;
            case 5: 
                cout << "Delete" << endl; 
                cin >> x;
                remove(x);
                break;
        }
    }while(n!=6);
    cout << "End:" << endl;
    
    //delete node
    node* t;
    while(start)
    {
        t = start->next;
        delete start;
        start = t;
    }
    return 1;
}
