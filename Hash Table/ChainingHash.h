#ifndef CHAINING_HASH_H
#define CHAINING_HASH_H

typedef struct node
{
  char* _key;
  char* _value;

  struct node* _next;
}Node;

typedef Node* List;

class ChainHash
{
  int tableSize;
  List* CH;

public:
  ChainHash(int _size);
  ~ChainHash();

  void setCH( char* _key, char* _value );
  void getCH( char* _key );

private:
  int calculateKey( char* _key );
  Node* createNode( char* _key, char* _value );
  void destroyNode( Node* _deNode );
  void destroyList( List _deList );
};

#endif
