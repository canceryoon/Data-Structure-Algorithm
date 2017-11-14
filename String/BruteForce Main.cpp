#include <iostream>
#include <string.h>
#include <stdio.h>

#include "BruteForce.h"

#define MAX_BUFFER 512

using namespace std;
int main(int argc, char **argv)
{
  char *filePath;
  FILE *fpx;

  char text[MAX_BUFFER];
  char *pattern;
  int patternLen = 0;
  int line = 0;

  if( argc < 3 )
  {
    cout << "Usage: " << argv[0] << " <FilePath> <Pattern>"<< endl;
    return 1;
  }

  filePath = argv[1];
  pattern = argv[2];

  patternLen = strlen(pattern);

  fpx = fopen(filePath, "r");
  if( fpx == NULL )
  {
    cout << "Can not open file " << filePath << endl;
    return 1;
  }

  while( fgets( text, MAX_BUFFER, fpx) != NULL )
  {
    int pos = bruteForce( text, strlen(text), 0, pattern, patternLen);
    if( pos >= 0 )
      cout << "Line: " << line++ << " pos: " << pos << " : " << text << endl;
  }

  fclose(fpx);
  return 0; 
}
