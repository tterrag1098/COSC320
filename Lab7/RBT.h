#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class TNode;

#include "TNode.h"
#include <iostream>
#include <cstdio>
#include <climits>

class RBT
{
  friend class TNode;

public:
    RBT();
    ~RBT();
    void inOrder();
    void preOrder();
    void postOrder();

    void insert(int data);
    void del(int data);
    TNode* search(int data);

    void print();
private:
    TNode *root = NULL;
    static TNode *nil;
    static constexpr int special_data = INT_MIN;

    TNode* search(TNode *from, int data);
    void inOrder(TNode *from);
    void preOrder(TNode *from);
    void postOrder(TNode *from);

    TNode* max(TNode *x);
    TNode* min(TNode *x);
    TNode* successor(TNode *x);
    TNode* predecessor(TNode *x);

    void leftRotate(TNode *x);
    void rightRotate(TNode *x);
    void insertFixUp(TNode *x);
    void deleteFixUp(TNode *t);

    int print(TNode *tree, int is_left, int offset, int depth, char s[20][255]);
};

#endif // BINARYSEARCHTREE_H
