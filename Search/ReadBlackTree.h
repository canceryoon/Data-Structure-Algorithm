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
};

#endif