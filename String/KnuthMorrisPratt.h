#ifndef KNUTHMORRISPRATT_H 
#define KNUTHMORRISPRATT_H

#include <iostream>

int knuthmorrispratt(char *text, int textLen, int st, char *pt, int ptLen);
void preprocess(char *pt, int ptLen, int *border);

#endif
