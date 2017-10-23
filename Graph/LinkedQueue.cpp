#include "LinkedQueue.h"


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

Node*  LQueue::DeQueue()
{
    if(!cnt)
    {
        return NULL;
    }
    Node* _front ; 
    if( cnt == 1 )
    {
	_front = front;
	free(front->_data);
        free(front);
        front = NULL;
        rear = NULL;
    }
    else
    {
	_front = front;
        Node* nfront = front->next;
	free(front->_data);
        free(front);
        front = nfront;
    }
    cnt--;
    return _front;
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

bool LQueue::IsEmpty()
{
  return ((front == NULL)? true : false);
}
