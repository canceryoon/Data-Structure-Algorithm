#include "OpenAddrHash.h"
HashTable::HashTable(int _size):tableSize(_size), usingCnt(0)
{
  table = (Node*)malloc(sizeof(Node)*tableSize);
}

HashTable::~HashTable()
{
  for(unsigned int i = 0; i < usingCnt; i++)
    destroyNode(&table[i]);
  
  free(table);
  tableSize = 0;
  usingCnt = 0;
}

void HashTable::destroyNode(Node* _deNode)
{
  if(_deNode->_Status == EMPTY) return;

  free(_deNode->_key);
  free(_deNode->_value);
}

int HashTable::calculateAddr(char* _key)
{
  int HashValue = 0;
  for(unsigned int i = 0; i < strlen(_key); i++)
    HashValue = (HashValue << 3) + _key[i];

  return HashValue % tableSize;
}

int HashTable::calculateStep(char* _key)
{
  int HashValue = 0;
  for(unsigned int i = 0; i < strlen(_key); i++)
    HashValue = (HashValue << 2) + _key[i];

  return (HashValue % (tableSize - 3)) + 1;
}

void HashTable::get(char* _key)
{
  int addr = calculateAddr(_key);
  int step = calculateStep(_key);

  while(table[addr]._Status == USING)
  {
    if( strcmp(table[addr]._key, _key) == 0 )
    {
      std::cout << table[addr]._key << " data is " << table[addr]._value << std::endl;
      return ;
    }
    addr = (addr + step) % tableSize;
  }
  std::cout << _key << " has no data" << std::endl;
}

void HashTable::set(char* _key, char* _value)
{
  int addr = calculateAddr(_key);
  int step = calculateStep(_key);

  double usage = (double)usingCnt / tableSize;
  if( usage > 0.7 )
    table = ReHash();

  while(table[addr]._Status == USING)
    addr = (addr + step) % tableSize;

  table[addr]._Status = USING;
  table[addr]._key = (char*)malloc(sizeof(char)*(strlen(_key)+1));
  table[addr]._value = (char*)malloc(sizeof(char)*(strlen(_value)+1));
  strcpy(table[addr]._key, _key);
  strcpy(table[addr]._value, _value);
  
  usingCnt++;
}

Node* HashTable::ReHash()
{
  Node* oldT = table;
  int size = tableSize;

  Node* newT = (Node*)malloc(sizeof(Node)*tableSize*2);
  tableSize = tableSize*2;
  table = newT;
  usingCnt = 0;

  for(unsigned int i = 0; i < tableSize; i++)
  {
    if(oldT[i]._Status == USING)
      set(oldT[i]._key, oldT[i]._value);
  }
}
