#include<iostream>
#define SELECT_TRUE 0x1
#define DELETE_TRUE 0x2
#define UPDATE_TRUE 0x3

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
	if(!HEAD)
	{
		cout << "No create List." << endl;
		return;
	}
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
	if(!HEAD)
	{
		cout << "No create Node." << endl;
		return;
	}
	while(1)
	{
		cout << node->prev->val << " " << node->val << " " << node->next->val << endl;
		node = node->next;
		if(node == HEAD) break;
	}
}

void showNode(int offset)
{	
	node* head = HEAD;
	int cnt = 1;
	if(!HEAD)
	{
		cout << "No create List." << endl;
		return;
	}

	do
	{
		if( cnt++ == offset)
		{
			cout << offset << " offset node value : " << head->val << endl;
			return ;
		}
		head = head->next;
	}while( head != HEAD);
	cout << "No " << offset << " Node." << endl;
} 

void deleteALLNode()
{
	node* head = HEAD;
	node* tmp;
	
	if(!HEAD)
	{
		cout << "No create List." << endl;
		return;
	}
	
	while(head)
	{
		if(head->next == head)
		{
			cout << "Delete value: " << head->val << endl;
			delete head;
			head = NULL;
			break;
		}		
		cout << "Delete value: " << head->val << endl;
		head->prev->next = head->next;
		head->next->prev = head->prev;
		tmp = head->next;
		
		delete head;
		head = NULL;
		head = tmp;
	}
}

void deleteNode(int offset)
{
	node* head = HEAD;
	node* tmp;
	int cnt = 1;
	if(!HEAD)
	{
		cout << "No create List." << endl;
		return;
	}	

	do
	{
		if( cnt++ == offset)
		{
			head->next->prev = head->prev;
			head->prev->next = head->next;

			delete head;
			head = NULL;
			return;
		}
		head = head->next;
	}while( head != HEAD);
	cout << "No create " << offset << " node." << endl;
} 

void updateNode(int offset, int val)
{
	node* head = HEAD;
	int cnt = 1;
	if(!HEAD)
	{
		cout << "No create List." << endl;
		return;
	}
		
	do
	{
		if( cnt++ == offset)
		{
			head->val = val;
			return;
		}
		head = head->next;
	}while( head != HEAD);
	cout << "No " << offset << " Node." << endl;
}

int main()
{
	int x, val, offset;
	do
	{
		cout << endl << "1. Insert" << endl << "2. InsertNode" << endl << "3. ShowNode" << endl << "4. ShowAll" << endl << "5. DeleteNode" << endl << "6 UpdateNode" << endl << "7. ENd" << endl;
		cin >> x;
		switch(x)
		{
			case 1: 
				cout << "Input Num: " ;
				cin >> val;
				appendNode(createNode(val));
				break;
			case 2: 
				cout << "Input Insert offset: "; 
				cin >> offset;
				cout << "Input Num: ";
				cin >> val;
				insertNode(offset, createNode(val));
				break;
			case 3:
				cout << "Input Select offset" ;
				cin >> offset;
				showNode(offset);
				break;
			case 4:
				showAllNode();
				break;
			case 5:
				cout << "Input Delete Offset";
				cin >> offset;
				deleteNode(offset);
				break;
			case 6:
				cout << "Input Update Offset";
				cin >> offset;
				cout << "Input Update NUm";
				cin >> val;
				updateNode(offset, val);
		}
	}while(x != 7);
	cout << "END:" << endl;
	deleteALLNode();
	return 1;
}
