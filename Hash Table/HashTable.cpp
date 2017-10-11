#include <stdlib.h>
#include "HashTable.h"

HashTable::HashTable(int _size):tableSize(_size), usedSize(0)
{
	HT = (Node*)malloc(sizeof(Node)*_size);
}

HashTable::~HashTable()
{
	free(HT);
}

int HashTable::calculateKey( int _key )
{
	return _key % tableSize ;
}

bool HashTable::set( int _key, int _values )
{
	if( usedSize == tableSize )
		return false;
		
	int addr = calculateKey( _key );
	HT[addr]._key = _key;
	HT[addr]._value = _values;
	usedSize++;
	
	return true;
}

int HashTable::get( int _key )
{
	int addr = calculateKey( _key );
	return HT[addr]._value;
}