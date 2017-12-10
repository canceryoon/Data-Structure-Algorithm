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

int knuthmorrispratt(char *text, int textLen, int st, char *pt, int ptLen)
{
	int i = st;
	int j = 0;
	int pos = -1;
	int *border = (int*)malloc(sizeof(int) * (ptLen + 1));
	preprocess(pt, ptLen, border);

	while (i < textLen)
	{
		if (j >= 0 && (text[i] != pt[j]))
			j = border[j];
		i += 1;
		j += 1;

		if (j == ptLen)
		{
			pos = i - j;
			break;
		}
	}
	free(border);
	return pos;
}