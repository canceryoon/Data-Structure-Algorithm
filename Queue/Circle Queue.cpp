#include<iostream>
using namespace std;

struct Node{
    int data;
};

class CircleQueue{
public:
    int size;
    int front;
    int rear;
    int cnt ;
    Node* node;

    CircleQueue(int _size)
    {
        size = _size;
        cnt = 1;
        front = 0;
        rear = 0;
        node = (Node*)malloc(sizeof(Node)* (size+1));
    }
    ~CircleQueue()
    {
        cout << "Destroy Queue" << endl;
        DestroyQueue();
    }

    void DestroyQueue();
    void InQueue(int _data);
    int DeQueue();
    int IsEmpty();
    int IsFull();
    void PrintQueue();

    
};

void CircleQueue::DestroyQueue()
{
    free(node);
}
void CircleQueue::InQueue( int _data )
{
    cout << cnt << " " << size << endl;
    if( cnt == size+1 ){ cout << "Full circle queue" << endl; return ;}
    int pos = 0;
    if( rear == size )
    {
        pos = rear;
        rear = 0;
    }
    else
    {
        pos = rear++;
    }
    cnt++;
    node[pos].data = _data;
}

int CircleQueue::DeQueue()
{
    if( cnt-1 == 0 ){ cout << "No data in circle queue" << endl; return -1;}
    int pos = front;
    if( front == size ) front = 0;
    else front++;

    cnt--;
    return node[pos].data;
}

int CircleQueue::IsEmpty()
{
    return (front == rear);
}

int CircleQueue::IsFull()
{
    if( front < rear ) return ((rear - front) == size);
    return ((rear +1) == front );
}

void CircleQueue::PrintQueue()
{
    unsigned int i;
    cout << "Print Queue" << endl;
    cout << "[" ;
    if( front > rear )
    {
        for( i = front; i <= size ; i++ ) cout << node[i].data << " ";
        for( i = 0; i < rear ; i++ ) cout << node[i].data << " " ;
    }
    else
    {
        for( i = front ; i < rear; i++) cout << node[i].data << " " ;
    }
    cout << "]" << endl;
}

int main()
{
    int _size;
    int x;
    int _data;
    cout << "Enter the Circle Queue size : ";
    cin >> _size;

    CircleQueue mCIQ(_size);

    do
    {
        cout << "1. Insert Queue   2. Delete Queue   3 Print Queue   4. End" << endl;
        cin >> x ;
        switch(x)
        {
            case 1: cout << "Enter the insert data :"; 
                    cin >> _data;
                    mCIQ.InQueue(_data);
                    break;
            case 2: cout << "Delete Queue Data: " << mCIQ.DeQueue() << endl;
                    break;
            case 3: mCIQ.PrintQueue(); break;  
            case 4: cout << "END:" << endl;
                    break;
        }
    }while( x != 4 );

    return 1;
}