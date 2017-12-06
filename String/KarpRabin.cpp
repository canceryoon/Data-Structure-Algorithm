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
  int textlen = strlen(text);

  int coefficient = pow(2, patternLen - 1);
  cout << "patternLen: " << pattenLen << endl;

  int hashText = hash(text, pattenLen);
  int hashPattern = hash(pattern, patternLen);

  for(; i <= textLen; i++)
  {
    hashText = rehash(text, i, patternLen - 1, hashText, coefficien);
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
