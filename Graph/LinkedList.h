#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "string.h"
#include "stdlib.h"
#include "Graph.h"

#define SEARCH_TRUE 0x1
#define DELETE_TRUE 0x2
#define UPDATE_TRUE 0x3

struct node
{
    myVertex* val;
    node* next;
};
typedef struct node Node;

void insert(node* start, myVertex* x);
void insertNHead(node** oldH, node* newH);
void select(node* start);
void search(node* start, myVertex* x);
void remove(node* start, myVertex* x);
void update(node* start, myVertex* _x, myVertex* x);

#endif
