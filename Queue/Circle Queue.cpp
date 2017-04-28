#include<iostream>
using namespace std;

struct Node{
    int Data;
};

class CircleQueue{
public:
    int size;
    int front;
    int rear;
    Node* node;

    CircleQueue(int _size)
    {
        size = _size;
        front = 0;
        rear = 0;
        node = (Node*)malloc(sizeof(Node)* (size+1));
    }
    ~CircleQueue()
    {
        cout << "Destroy Queue" << endl;

    }

    void InQueue( int _data )
    {
        int pos = 0;
        if( rear == size )
        {
            pos = rear;
            rear = 0;
        }
        else
        {
            pos = rear++;
            node.data = _data;
        }
    }
};