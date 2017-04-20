#include<iostream>
using namespace std;

struct node
{
	int val;
	node* prev;
	node* next;
};

node* HEAD;

node* createNode(int _val)
{
	node* tmp = new node;
	tmp->val = _val;
	tmp->next = NULL;
	tmp->prev = NULL;
	
	return tmp;
}

void appendNode(node* inNode)
{
	if(HEAD)
	{
		node* head = HEAD;
		head->prev->next = inNode;
		inNode->prev = head->prev;
		
		head->prev = inNode;
		inNode->next = head;
	}
	else
	{
		HEAD = inNode;
		HEAD->next = HEAD;
		HEAD->prev = HEAD;
	}
}

void insertNode(int offset, node* inNode)
{
	node* node = HEAD;
	int cnt=1;
	while(node->next != HEAD)
	{
		if( cnt == offset )
		{
			inNode->prev = node->prev;
			inNode->next = node;
			
			node->prev->next = inNode;
			node->prev = inNode;
			
			return;
		}
		cnt++;
		node = node->next;
	}
	delete inNode;
	cout << "No offset" << endl;
}

void showAllNode()
{
	node* node = HEAD;
	while(1)
	{
		cout << node->prev->val << " " << node->val << " " << node->next->val << endl;
		node = node->next;
		if(node == HEAD) break;
	}
}

/* void showNode(int offset)
{

} */

void deleteALLNode()
{
	node* head = HEAD;
	node* tmp;
	
	if(!HEAD)
	{
		cout << "No create List." << endl;
		return;
	}
	
	while(head->next != head)
	{
		if(head->next == head)
		{
			cout << "Delete value: " << head->val << endl;
			delete head;
			return;
		}		
		cout << "Delete value: " << head->val << endl;
		head->prev->next = head->next;
		head->next->prev = head->prev;
		tmp = head->next;
		
		delete head;
		head = tmp;
	}
}

/* void deleteNode(int offset)
{

} */

int main()
{
	int x, val, offset;
	do
	{
		cout << endl << "1. Insert" << endl << "2 InsertNode" << endl << "3. ShowAll" << endl << "4 END" << endl;
		cin >> x;
		switch(x)
		{
			case 1: 
				cout << "Input Num: " ;
				cin >> val;
				appendNode(createNode(val));
				break;
			case 2: 
				cout << "Input offset: "; 
				cin >> offset;
				cout << "Input Num: ";
				cin >> val;
				insertNode(offset, createNode(val));
				break;
			case 3:
				showAllNode();
				break;
		}
	}while(x != 4);
	cout << "END:" << endl;
	deleteALLNode();
	return 1;
}
