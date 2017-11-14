#include "BruteForce.h"

int bruteForce(char* in, int inLen, int pos, char* pattern, int patternLen)
{
  unsigned int i = 0;
  unsigned int j = 0;

  for(; i <= inLen - patternLen; i++)
  {
    for( j = 0; j < patternLen; j++)
      if( in[i+j] != pattern[j] )
	break;
    if( j >= patternLen )
	return i;
  }
  return -1;
}
