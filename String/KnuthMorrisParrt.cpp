#include "KnuthMorrisPratt.h"

void preprocess(char *pt, int ptLen, int *border)
{
	int i = 0;
	int j = border[0] = -1;
	while (i < ptLen)
	{
		if (j > -1 && pt[i] != pt[j])
			j = border[j];
		i += 1;
		j += 1;
		border[i] = j;
	}
}
