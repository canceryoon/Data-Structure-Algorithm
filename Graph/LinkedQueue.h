#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

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
    Node* DeQueue();
    void PrintQueue();
    bool IsEmpty();
};

#endif
