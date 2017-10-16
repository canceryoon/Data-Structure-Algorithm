#ifndef OPEN_ADDR_HASH_H
#define OPEN_ADDR_HASH_H

#include <stdlib.h>
#include <string.h>
#include <iostream>

enum status
{
  EMPTY = 0,
  USING 
};

typedef struct node
{
  char* _key;
  char* _value;

  enum status _Status;
}Node;

class HashTable{
  Node* table;
  int tableSize;
  int usingCnt;

public:
  HashTable(int size);
  ~HashTable();

  void set(char* _key, char* _value);
  void get(char* _key);

private:
  int calculateAddr(char* _key);
  int calculateStep(char* _key);
  Node* ReHash();
  void destroyNode( Node* _deNode );
};
#endif
