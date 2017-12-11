#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "KnuthMorrisPratt.h"

#include <string.h>
#include <stdio.h>

#define MAX_BUFFER 512

using namespace std;
int main(int argc, char **argv)
{
	const char *filePath;
	FILE *fpx;

	char text[MAX_BUFFER];
	char *pattern;
	int patternLen = 0;
	int line = 0;
	bool find = false;

	if (argc < 3)
	{
		cout << "Usage: " << argv[0] << " <FilePath> <Pattern>" << endl;
		return 1;
	}

	filePath = argv[1];
	pattern = argv[2];

	fpx = fopen(filePath, "r");
	if (fpx == NULL)
	{
		cout << "Can not open file " << filePath << endl;
		return 1;
	}

	while (fgets(text, MAX_BUFFER, fpx) != NULL)
	{
		int pos = knuthmorrispratt(text, (int)strlen(text), 0, pattern, (int)strlen(pattern));
		line += 1;
		if (pos >= 0)
		{
			cout << "Line: " << line << " pos: " << pos << " : " << text << endl;
			find = true;
		}
	}

	if (!find)
		cout << filePath << " has no pattern: " << pattern << endl;

	fclose(fpx);
	return 0;
}
