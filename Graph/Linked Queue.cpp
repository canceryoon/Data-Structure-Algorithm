#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"

using namespace std;

struct Node{
    myVertex* _data;
    Node* next;
};

class LQueue
{
public:
    Node* front;
    Node* rear;
	int cnt;
	
	LQueue()
    { 
        cnt = 0;
        front = NULL;
        rear = NULL;
    }
	~LQueue()
	{
		std::cout << "In Destructor " << std::endl;
		Node* pNode = front;
        for(unsigned int i = 1; i <= cnt ; i++)
        {
            DeQueue();
        }
		front = NULL;
        rear = NULL;
	}

    void InQueue(myVertex* data);
    void DeQueue();
    void PrintQueue();
};

void LQueue::InQueue(myVertex* data)
{
    Node* node = (Node*)malloc(sizeof(Node)) ;
    node->_data = (myVertex*)malloc(sizeof(myVertex));
    memcpy(node->_data, data, sizeof(myVertex));
    node->next = NULL;

    if( !cnt )
    {
        front = node;
    }
    else
    {
        rear->next = node;
    }
    rear = node;
    cnt++;
}

void  LQueue::DeQueue()
{
    if(!cnt)
    {
        cout << "No data int LQueue" << endl;
        return ;
    }
    if( cnt == 1 )
    {
	free(front->_data);
        free(front);
        front = NULL;
        rear = NULL;
    }
    else
    {
        Node* nfront = front->next;
	free(front->_data);
        free(front);
        front = nfront;
    }
    cnt--;
}

void LQueue::PrintQueue()
{
    if(!cnt)
    {
        cout << "No data int LQueue" << endl;
        return ;
    }
    
    Node* pNode = front;
    for(unsigned int i = 1; i <= cnt ; i++)
    {
        cout << pNode->_data->data << " " ;
        pNode = pNode->next;
    }
    cout << endl;
}
