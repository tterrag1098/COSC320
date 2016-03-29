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

#include "BST.h"

BST::BST()
{

}

BST::~BST()
{

}

TNode* BST::max(TNode* x)
{
  return x->right ? max(x->right) : x;
}

TNode* BST::min(TNode* x)
{
  return x->left ? min(x->left) : x;
}

TNode* BST::successor(TNode* x)
{
  if (x->right)
  {
    return min(x->right);
  }
  TNode *y = x->parent;
  while (y && x == y->right)
  {
    x = y;
    y = y->parent;
  }
  return y;
}

TNode* BST::predecessor(TNode* x)
{
  if (x->left)
  {
    return max(x->left);
  }
  TNode* y = x->parent;
  while (y && x == y->left);
  {
    x = y;
    y = y->parent;
  }
  return y;
}

TNode* BST::search(int data)
{
  return search(root, data);
}

TNode* BST::search(TNode* from, int data)
{
  if (!from || from->data == data) return from;
  if (data < from->data) return search(from->left, data);
  else return search(from->right, data);
}

void BST::insert(int data)
{
  TNode *x = root;
  TNode *y = NULL;
  while (x)
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
  if (!y)
  {
    // Empty tree
    x = root = newNode;
  }
  else if (data < y->data)
  {
    y->left = newNode;
  }
  else
  {
    y->right = newNode;
  }
}

void BST::del(int data)
{
  TNode *z = search(data);
  if (!z) return;
  
  TNode *x, *y;
  x = y = NULL;
  
  if (!z->left || !z->right)
  {
    y = z;
  }
  else
  {
    y = successor(z);
  }
  
  x = y->left ? y->left : y->right;
  
  if (x)
  {
    x->parent = y->parent;
  }
  if (!y->parent)
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
  
  delete y;
}

void BST::inOrder()
{
  inOrder(root);
  std::cout << std::endl;
}

void BST::inOrder(TNode* from)
{
  if (from)
  {
    inOrder(from->left);
    std::cout << from->data << " ";
    inOrder(from->right);
  }
}

void BST::preOrder()
{
  preOrder(root);
  std::cout << std::endl;
}

void BST::preOrder(TNode* from)
{
  if (from)
  {
    std::cout << from->data << " ";
    preOrder(from->left);
    preOrder(from->right);
  }
}

void BST::postOrder()
{
  postOrder(root);
  std::cout << std::endl;
}

void BST::postOrder(TNode* from)
{
  if (from)
  {
    postOrder(from->left);
    postOrder(from->right);
    std::cout << from->data << " ";
  }
}

using namespace std;

int BST::print(TNode *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->data);

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

void BST::print()
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    print(root, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}
