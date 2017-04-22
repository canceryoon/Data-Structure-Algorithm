#define SELECT_TRUE 0x1
#define DELETE_TRUE 0x2
class Node;
class CDList;

static bool hasList(Node* head)
{
	if(head) return true;

	std::cout << "No create node." << std::endl;
	return false;
}

class Node
{
public:
	int val;
	Node* next;
	Node* prev;

	Node(){ }
	Node(int _val)
	{
		val = _val;
		next = NULL;
		prev = NULL;
	}
	~Node()
	{
		next = NULL;
		prev = NULL;
	}
	
};

class CDList
{
public:
    Node* head;
	int nodeCnt;
	
	CDList(){ head = NULL; nodeCnt = 0;}
	CDList(Node* _node)
	{
		head = NULL;
		nodeCnt = 0;
		insert(_node);
	}
	~CDList()
	{
		deleteAllNode();
		head = NULL;
	}
	
    void insert(Node* node);
	/*void insertOffset(int offset, Node* node);*/
	void select();/*
	void selectOffset(int offset);*/
	void selectData(int _val);
	void deleteAllNode();
	/*
	void deleteOffset(int offset);
	void deleteData(int _val);
	*/
	int totalCount();
};

void CDList::insert(Node* node)
{
	if(head)
	{
		node->next = head;
		node->prev = head->prev;

		head->prev->next = node;
		head->prev= node;
	}
	else
	{
		head = node;
		head->next = node;
		head->prev = node;
	}
	nodeCnt++;
}
/*
void CDList::insertOffset(int offset, Node* node)
{
} 
*/
void CDList::select()
{
	if(hasList(head))
	{
		std:: cout << "Select Func" << std::endl;
	}
}
/*
void CDList::selectOffset(int offset)
{
}
*/
void CDList::selectData(int _val)
{
	if(hasList(head))
	{
		int flag;
		do{
			if(head->val == _val)
			{
				std::cout << head->val << std::endl;
				flag = SELECT_TRUE;
			}
			head = head->next;
		}while(head->next == head);
		if( flag ^ SELECT_TRUE ) std::cout << "Data "<< _val <<" is not in nodes." << std::endl;
	}
}

void CDList::deleteAllNode()
{
	if(hasList(head))
	{
		Node* tmp;
		do
		{
			tmp = head->next;
			head->next->prev = head->prev;
			head->prev->next = head->next;

			std::cout << "Delete Node`s data : " << head->val << std::endl;
			delete head;
			head = tmp;
		}while(head != head->next);
		std::cout << "Delete Node`s data : " << head->val << std::endl;
		delete head;
		head = NULL;
	}
}
/*
void CDList::deleteOffset(int offset)
{
}

void CDList::deleteData(int _val)
{
}
*/
int CDList::totalCount()
{
	return nodeCnt;
} 
