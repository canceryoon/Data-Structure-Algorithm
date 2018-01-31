#include "BoyerMoore.h"
#include <stdlib.h>

int BoyerMoore(char *text, int textLen, char *pt, int ptLen, int _st)
{
	int bct[128];
	int *suffix = (int*)malloc((ptLen+1)*sizeof(int));
	int *gst = (int*)malloc((ptLen+1)*sizeof(int));
	int st = _st;
	int i = 0;
	int pos = -1;

	MakeGST(pt, ptLen, suffix, gst);
	MakeBCT(pt, ptLen, bct);

	while(st <= (textLen - ptLen))
	{
		i = ptLen - 1;
		while( i >= 0 && pt[i] == text[st + i] )
			i--;
		
		if(i < 0)
		{
			pos = st;
			break;
		}
		st += std::max(gst[i + 1], i - bct[text[st + i]]);
	}

	
	free(suffix);
	free(gst);
	
	return pos;
} 

void MakeGST(char *pt, int ptLen, int *suffix, int *gst)
{
	int i = ptLen;
	int j = ptLen + 1;

	suffix[i] = j;
	while( i > 0 )
	{
		while(j <= ptLen && pt[i-1] != pt[j-1])
		{
			if(gst[j] == 0)
				gst[j] = j - i;
			j = suffix[i];
		}
		i--;
		j--;
	}

	j = suffix[0];
	for(i = 0; i <= ptLen; i++)
		if(gst[i] == 0)
			gst[i]=j;
		else if(i == j)
			j = suffix[j];
}

void MakeBCT(char *pt, int ptLen, int *bct)
{
	int i;
	for(i = 0; i < 128; i++)
		bct[i] = -1;

	for(i = 0; i < ptLen; i++)
		bct[pt[i]] = i;
}

