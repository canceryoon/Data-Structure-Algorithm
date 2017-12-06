#include "KarpRabin.h"
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
int KarpRarbin( char *text, char *pattern, int st)
{
  int i = st;
  int j = 0;

  int patternLen = strlen(pattern);
  int textLen = strlen(text);

  int coefficient = pow(2, patternLen - 1);
  cout << "patternLen: " << patternLen << endl;

  int hashText = hash(text, patternLen);
  int hashPattern = hash(pattern, patternLen);

  for(; i <= textLen; i++)
  {
    hashText = rehash(text, i, patternLen - 1, hashText, coefficient);
    if( hashPattern == hashText )
    {
      for( j = 0; j < patternLen; j++)
	if( text[i+j] != pattern[j] ) 
	  break;

      if( j >= patternLen )
	return i;
    }
  }

  return -1;
}

inline int hash( char *str, int _size )
{
  int i = 0;
  int hashval = 0;
  
  for(; i < _size; i++)
    hashval = str[i] + (hashval << 1);

  return hashval;
}

inline int rehash( char *str, int st, int _size, int hashPrev, int coefficient )
{
  return (st == 0)? hashPrev : (str[st + _size] + ( (hashPrev - coefficient * str[st-1]) << 1 ));
}

