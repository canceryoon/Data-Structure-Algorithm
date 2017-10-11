#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct node
{
	int _key;
	int _value;
} Node;

class HashTable
{
	int tableSize;
	int usedSize;
	Node* HT;

public:
	HashTable(int _size);
	~HashTable();

	bool set( int _key, int _value );
	int get( int _key );
	int calculateKey( int _key );
};

#endif