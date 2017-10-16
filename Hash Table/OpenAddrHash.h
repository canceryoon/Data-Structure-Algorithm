#ifndef OPEN_ADDR_HASH_H
#define OPEN_ADDR_HASH_H

enum status;
{
  EMPTY = 0,
  USING 
}

typedef struct node
{
  char *_key;
  char *_value;

  enum status Status;
}Node;

class HashTable{
  Node* table;
  int tableSize;
  int usingCount;

public:
  HashTable(int size);
  ~HashTable();

private:
  void set(char* _key, char* _value);
  void get(char* _key);
  int hash(char* _key);
  int hash2(char* _key);
  Node* ReHash();
};
#endif
