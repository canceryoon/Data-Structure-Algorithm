#include<iostream>
using namespace std;

struct Node{
    int _data;
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

    void InQueue(int data);
    int DeQueue();
    void PrintQueue();
};

void LQueue::InQueue(int data)
{
    Node* node = (Node*)malloc(sizeof(Node)) ;
    node->_data = data;
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

int LQueue::DeQueue()
{
    if(!cnt)
    {
        cout << "No data int LQueue" << endl;
        return -1;
    }
    int deData = front->_data;
    if( cnt == 1 )
    {
        free(front);
        front = NULL;
        rear = NULL;
    }
    else
    {
        Node* nfront = front->next;
        free(front);
        front = nfront;
    }
    cnt--;
    return deData;
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
        cout << pNode->_data << " " ;
        pNode = pNode->next;
    }
    cout << endl;
}

int main()
{
    LQueue myLQ;
    int x, _data;
    do
    {
        cout << "1. Insert Q   2. Delete Q   3. Print Q   4. End" << endl;
        cin >> x;
        switch(x)
        {
            case 1: cout << "Enter the data:" ;
                    cin >> _data;
                    myLQ.InQueue(_data);
                    break;
            case 2: cout << "Delete Queue data: " << myLQ.DeQueue() << endl; break;
            case 3: myLQ.PrintQueue();
        }
    }while( x != 4);
    return 1;
}