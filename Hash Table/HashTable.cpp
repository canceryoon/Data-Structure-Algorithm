#include <stdlib.h>
#include "HashTable.h"

HashTable::HashTable(int _size):tableSize(_size)
{
	HT = (Node*)malloc(sizeof(Node)*_size);
}