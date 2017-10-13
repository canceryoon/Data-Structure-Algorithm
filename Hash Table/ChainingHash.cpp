#include <stdlib.h>
#include <string.h>
#include <iostream>
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

Node* ChainHash::createNode( char* _key, char* _value )
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->_key = (char*)malloc(sizeof(char)*(strlen(_key)+1));
  newNode->_value = (char*)malloc(sizeof(char)*(strlen(_value)+1));

  strcpy(newNode->_key, _key);
  strcpy(newNode->_value, _value);
  newNode->_next = NULL;
  
  return newNode;
}

int ChainHash::calculateKey( char* _key )
{
  int hashValue = 0;
  for(unsigned int i = 0; i < strlen(_key); i++)
    hashValue = (hashValue << 3) + _key[i];

  return hashValue % tableSize;
}

void ChainHash::setCH( char* _key, char* _value )
{
  int addr = calculateKey( _key );
  Node* _inNode = createNode( _key, _value );

  if( CH[addr] == NULL )
    CH[addr] = _inNode;
  else
  {
    List _tmp = CH[addr];
    _inNode->_next = _tmp;
    CH[addr] = _inNode;
  }
}

void ChainHash::getCH( char* _key )
{
  int addr = calculateKey( _key );
  
  if( CH[addr] == NULL )
  {
    std::cout << _key << " has no data in hash table." << std::endl;
    return ;
  }

  List _tmp = CH[addr];
  while(1)
  {
    if( strcmp( _key, _tmp->_key ) )
    {
      std::cout << _key << " has data: " << _tmp->_value << std::endl;
      return ;
    } 
    else
    {
      if( _tmp->_next != NULL )
        _tmp = _tmp->_next;	
      else
	break;
    }
  }

  std::cout << _key << " has no data in hash table." << std::endl;
}


