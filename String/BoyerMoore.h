#ifndef BOYERMOORE_H
#define BOYERMOORE_H

#include <iostream>

int BoyerMoore(char *text, int textLen, char *pt, int ptLen, int st);
void MakeGST(char *pt, int ptLen, int *suffix, int *gst);
void MakeBCT(char *pt, int ptLen, int *bst);
#endif 
