#ifndef KARPRABIN_H
#define KARPRABIN_H

int KarpRarbin( char *text, char *pattern, int st, int patternLen, int textLen );
int hash( char *str, int _size );
int rehash( char *str, int st, int _size, int hashPrev, int coefficient );
#endif
