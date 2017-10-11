#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct node
{
	int key;
	int value;
} Node;

class HashTable
{
	int tableSize;
	Node* HT;

public:
	HashTable(int _size);
};

#endif