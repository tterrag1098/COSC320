/*
 * Copyright (c) 2016 <copyright holder> <email>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "RBT.h"

TNode *RBT::nil = new TNode();

RBT::RBT()
{
  nil->parent = nil;
  nil->left = nil;
  nil->right = nil;

  root = nil;
}

RBT::~RBT()
{

}

TNode* RBT::max(TNode* x)
{
  return x->right != nil ? max(x->right) : x;
}

TNode* RBT::min(TNode* x)
{
  return x->left != nil ? min(x->left) : x;
}

TNode* RBT::successor(TNode* x)
{
  if (x->right != nil)
  {
    return min(x->right);
  }
  TNode *y = x->parent;
  while (y != nil && x == y->right)
  {
    x = y;
    y = y->parent;
  }
  return y;
}

TNode* RBT::predecessor(TNode* x)
{
  if (x->left != nil)
  {
    return max(x->left);
  }
  TNode* y = x->parent;
  while (y != nil && x == y->left);
  {
    x = y;
    y = y->parent;
  }
  return y;
}

TNode* RBT::search(int data)
{
  return search(root, data);
}

TNode* RBT::search(TNode* from, int data)
{
  if (from == nil || from->data == data) return from;
  if (data < from->data) return search(from->left, data);
  else return search(from->right, data);
}

void RBT::leftRotate(TNode* x)
{
  TNode *y = x->right;
  x->right = y->left;
  y->left->parent= x;
  y->parent = x->parent;

  if (x->parent == nil)
  {
    root = y;
  }
  else if (x == x->parent->left)
  {
    x->parent->left = y;
  }
  else
  {
    x->parent->right = y;
  }

  y->left = x;
  x->parent = y;
}

void RBT::rightRotate(TNode* x)
{
  TNode *y = x->left;
  x->left = y->right;
  y->right->parent= x;
  y->parent = x->parent;

  if (x->parent == nil)
  {
    root = y;
  }
  else if (x == x->parent->right)
  {
    x->parent->right = y;
  }
  else
  {
    x->parent->left = y;
  }

  y->right = x;
  x->parent = y;
}

void RBT::insert(int data)
{
  TNode *x = root;
  TNode *y = nil;
  while (x != nil)
  {
    y = x;
    if (data < x->data)
    {
      x = x->left;
    }
    else
    {
      x = x->right;
    }
  }

  TNode *newNode = new TNode();
  newNode->data = data;
  newNode->parent = y;
  if (y == nil)
  {
    // Empty tree
    x = root = newNode;
    newNode->color = BLACK;
    return;
  }
  else if (data < y->data)
  {
    y->left = newNode;
  }
  else
  {
    y->right = newNode;
  }

  newNode->color = RED;
  print();
  insertFixUp(newNode);
  print();
}

void RBT::insertFixUp(TNode* z)
{
  if (z->parent->color == BLACK) return;

  TNode *y = z->parent->parent;
  y = z->parent == y->left ? y->right : y->left;

  if (y->color == RED)
  {
    z->parent->color = y->color = BLACK;
    z->parent->parent->color = RED;
    insertFixUp(z->parent->parent);
  }
  else
  {
    if ((z == z->parent->right) == (y == z->parent->parent->right))
    {
      TNode *q = z;
      z = z->parent;
      if (q == q->parent->right) leftRotate(z);
      else rightRotate(z);
    }
    z->parent->color = BLACK;
    z->parent->parent->color = RED;
    if (z->parent == z->parent->parent->left) rightRotate(z->parent->parent);
    else leftRotate(z->parent->parent);
  }

  root->color = BLACK;
}

void RBT::del(int data)
{
  TNode *z = search(data);
  if (z == nil) return;

  TNode *x, *y;
  x = y = NULL;

  if (z->left == nil || z->right == nil)
  {
    y = z;
  }
  else
  {
    y = successor(z);
  }

  x = y->left != nil ? y->left : y->right;

  if (x != nil)
  {
    x->parent = y->parent;
  }

  if (y->parent == nil)
  {
    root = x;
  }
  else if (y == y->parent->left)
  {
    y->parent->left = x;
  }
  else
  {
    y->parent->right = x;
  }

  if (y != z)
  {
    z->data = y->data;
  }

  if (y->color == BLACK)
  {
    deleteFixUp(x);
  }

  delete y;
}

void RBT::deleteFixUp(TNode* x)
{

}

void RBT::inOrder()
{
  inOrder(root);
  std::cout << std::endl;
}

void RBT::inOrder(TNode* from)
{
  if (from)
  {
    inOrder(from->left);
    std::cout << from->data << " ";
    inOrder(from->right);
  }
}

void RBT::preOrder()
{
  preOrder(root);
  std::cout << std::endl;
}

void RBT::preOrder(TNode* from)
{
  if (from)
  {
    std::cout << from->data << " ";
    preOrder(from->left);
    preOrder(from->right);
  }
}

void RBT::postOrder()
{
  postOrder(root);
  std::cout << std::endl;
}

void RBT::postOrder(TNode* from)
{
  if (from)
  {
    postOrder(from->left);
    postOrder(from->right);
    std::cout << from->data << " ";
  }
}

using namespace std;

int RBT::print(TNode *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 7;

    if (tree == nil) return 0;

    sprintf(b, "(%03d)-%s", tree->data, tree->color == BLACK ? "B" : "R");

    int left  = print(tree->left,  1, offset,                depth + 1, s);
    int right = print(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}

void RBT::print()
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    print(root, 0, 0, 0, s);

    for (int i = 0; i < 10; i++)
        printf("%s\n", s[i]);
}
