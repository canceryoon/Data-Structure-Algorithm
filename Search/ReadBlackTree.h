#ifndef READ_BLACK_TREE_H
#define READ_BLACK_TREE_H

enum {
    READ,
    BLACK
} Color;

struct RBTree{
    int data;

    RBTree* left;
    RBTree* right;
    RBTree* parent;
    Color color;
}RBNode;

RBNode* createRBNode(int data);
void destroyRBNode(RBNode* rnode);
void destroyRBTree(RBNode* tree);

RBNode* searchRBNode(RBNode* tree, int target);
RBNode* searchMinRBNode(RBNode* tree);
RBNode* removeNode(RBNode** tree, int data);

void insertNode(RBNode** tree, RBNode* nNode);
void insertNodeHelper(RBNode** tree, RBNode* nNode);
void rebuildAfterInsert(RBNode** tree, NODE* x);
void rebuildAfterRemove(RBNode** tree, RBNode* x);

void printTree(RBNode* node, int depth, int blackCount);
void rotateLeft(RBNode** root, RBNode* parent);
void rotateRight(RBNode** root, RBNode* parent);

#endif