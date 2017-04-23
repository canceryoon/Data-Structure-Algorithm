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
		std::cout << "In Destructor " << std::endl;
		deleteAllNode();
		head = NULL;
	}
	
    void insert(Node* node);
	void insertOffset(int offset, Node* node);
	void select();
	void selectOffset(int offset);
	void selectData(int _val);
	void deleteAllNode();
	void deleteOffset(int offset);
	void deleteData(int _val);
	int getNodeCnt();
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

void CDList::insertOffset(int offset, Node* node)
{
	if(hasList(head))
	{
		int cnt = 1;
		Node* HEAD = head;
		if( offset <= nodeCnt ) 
		{
			while( cnt++ != offset ) HEAD = HEAD->next;
			HEAD->prev->next = node;
			node->prev = HEAD->prev;
			HEAD->prev = node;
			node->next = HEAD;
			if( offset == 1 )
			{
				head = node;
			}
			nodeCnt++;
		}
		else std::cout << "Just Node has " << nodeCnt << " nodes." << std::endl;
	}
} 

void CDList::select()
{
	if(hasList(head))
	{
		Node* HEAD = head;
		do
		{
			std::cout << HEAD->prev->val << " " << HEAD->val << " " << HEAD->next->val << std::endl;
			HEAD = HEAD->next;
		}while(head != HEAD);
	}
}

void CDList::selectOffset(int offset)
{
	if(hasList(head))
	{
		if( offset > nodeCnt )
		{
			std::cout << "Just Node has " << nodeCnt << " nodes." << std::endl;
			return ;
		}
		int cnt = 1;
		Node* HEAD = head;
		do
		{
			if( cnt++ == offset )
			{
				std::cout << offset << " node`s data is : " << HEAD->val << std::endl;
			}
			HEAD = HEAD->next;
		}while(HEAD != head);
	}
}

void CDList::selectData(int _val)
{
	if(hasList(head))
	{
		int flag;
		int cnt = 1;
		Node* HEAD = head;
		do
		{
			if( HEAD->val == _val  )
			{
				std::cout << cnt << " node`s has data: " << HEAD->val << std::endl;
				flag = SELECT_TRUE;
			}
			cnt++;
			HEAD = HEAD->next;
		}while(HEAD != head);
		if( flag ^ SELECT_TRUE ) std::cout << "Data "<< _val <<" is not in nodes." << std::endl;
	}
}

void CDList::deleteAllNode()
{
	if(hasList(head))
	{
		Node* tmp = head;
		int cnt = 1;
		do
		{
			tmp = head->next;
			head->next->prev = head->prev;
			head->prev->next = head->next;
			std::cout << "Delete Node`s data : " << head->val << std::endl;
			delete head;
			head = NULL;
			head = tmp;	
		}while(++cnt <= nodeCnt);
		nodeCnt = 0;
	}
}

void CDList::deleteOffset(int offset)
{
	if(hasList(head))
	{
		int cnt = 1;
		Node* HEAD = head;
		if( offset <= nodeCnt ) 
		{
			while( cnt++ != offset ) HEAD = HEAD->next;
			HEAD->prev->next = HEAD->next;
			HEAD->next->prev = HEAD->prev;

			delete HEAD;
		}
		else std::cout << "Just Node has " << nodeCnt << " nodes." << std::endl;
	}
}

void CDList::deleteData(int _val)
{
	if(hasList(head))
	{
		int flag;
		Node* tmp;
		Node* HEAD = head;
		do
		{
			tmp = HEAD->next;
			if(HEAD->val == _val)
			{
				HEAD->prev->next = HEAD->next;
				HEAD->next->prev = HEAD->prev;
				delete HEAD;
				flag = DELETE_TRUE;
			}
			HEAD = tmp;
		}while(head != HEAD);
		if( flag ^ DELETE_TRUE ) std::cout << "Data "<< _val <<" is not in nodes." << std::endl;
	}
}

int CDList::getNodeCnt()
{
	return nodeCnt;
} 
