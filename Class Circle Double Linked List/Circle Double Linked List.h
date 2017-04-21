class Node
{
	int val;
	Node* next;
	Node* prev;
	Node(int _val)
	{
		val = _val;
		next = NULL;
		prev = NULL;
	}
	
};

class CDList
{
    Node head;
	int nodeCnt;
	CDList(){ head = NULL; nodeCnt = 0;}
	CDList(Node* _node)
	{
		head = NULL;
		nodeCnt = 0;
		insert(head);
	}
	~CDList()
	{
		deleteAllNode();
		head = NULL;
	}
	
public:
    void insert(Node* node);
	void insertOffset(int offset, Node* node);
	void select();
	void selectOffset(int offset);
	void selectData(int _val);
	void deleteAllNode();
	void deleteOffset(int offset);
	void deleteData(int _val);
	void totalCount();
};

/* void CDList::insert(Node* node)
{
}

void CDList::insertOffset(int offset, Node* node)
{
} 

void CDList::select()
{
}

void CDList::selectOffset(int offset)
{
}

void CDList::selectData(int _val)
{
}

void CDList::deleteAllNode()
{
}

void CDList::deleteOffset(int offset)
{
}

void CDList::deleteData(int _val)
{
}

void CDList::totalCount()
{
} */
