#include <stdlib.h>
#include "ChainingHash.h"

ChainHash::ChainHash( int _size ):tableSize(_size)
{
  CH = (List*)malloc(sizeof(List) * _size);
}

ChainHash::~ChainHash()
{
  List deList;

  for(unsigned int i = 0; i < tableSize; i++)
  {
    deList = CH[i];
    destroyList(deList);  
  }
  free(CH);
}

void ChainHash::destroyList( List _deList )
{
  if( _deList == NULL ) return ;

  if( _deList->_next != NULL ) 
    destroyList( _deList->_next );

  destroyNode( _deList );
}

void ChainHash::destroyNode( Node* _deNode )
{
  free(_deNode->_key);
  free(_deNode->_value);
  free(_deNode);
}

Node* createNode( char* _key, char* _value )
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->_key = (char*)malloc(sizeof(char)*(strlen(_key)+1));
  newNode->_value = (char*)malloc(sizeof(char)*(strlen(_value)+1));

  strcpy(newNode->_key, _key);
  strcpy(newNode->_value, _value);
  newNode->_next = NULL;
  
  return newNode;
}

itn calculateKey( char* _key )
{
  
}
