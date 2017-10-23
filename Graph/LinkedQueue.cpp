#include "LinkedQueue.h"


void LQueue::InQueue(myVertex* data)
{
    Node* node = (Node*)malloc(sizeof(Node)) ;
    node->_data = (myVertex*)malloc(sizeof(myVertex));
    memcpy(node->_data, data, sizeof(myVertex));
    node->next = NULL;

    if( cnt == 0 && front == NULL )
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
    Node* _front = front;
    if( front->next == NULL )
    {
      front = NULL;
      rear = NULL;
    }
    else
    {
      front = front->next;
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
