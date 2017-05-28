#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include<iostream>

struct NODE{
    int data;
    NODE* left;
    NODE* right;
};

NODE* createNode(int _data);
void destroyNode(NODE* rnode);
void destroyTree(NODE* tree);

void printNode(NODE* tree);
void insertNode(NODE* tree, NODE* child);
NODE* removeNode(NODE* tree, NODE* parent, int rdata);
NODE* searchNode(NODE* tree, int target);
NODE* searchMinNode(NODE* tree);



#endif