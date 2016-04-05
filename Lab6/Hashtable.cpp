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

#include "Hashtable.h"

Hashtable::Hashtable(int initialSize) : size(0), maxSize(initialSize)
{
  table = new Node*[maxSize];
}

Hashtable::~Hashtable() {}

Node::Node(int data) : data(data) {}

Node::~Node() {}

int Hashtable::h(int k)
{
  return k % maxSize;
}

void Hashtable::insert(int data)
{
   int addr = h(data);
   if (!table[addr])
   {
       table[addr] = new Node(data);
       size++;
   }
   else
   {
       Node *cur = table[addr];
       while (cur->next)
       {
	   if (cur->data == data)
	   {
	       return;
	   }
	   cur = cur->next;
       }
       cur->next = new Node(data);
       cur->next->prev = cur;
       size++;
   }
}

void Hashtable::remove(int data)
{
    int addr = h(data);
    if (table[addr])
    {
        Node *cur = table[addr];
	while (cur)
	{
	    if (cur->data == data)
	    {
	        if (cur->prev)
		{
		    cur->prev->next = cur->next;
		}
		else
		{
		    table[addr] = cur->next;
		}
		size--;
		return;
	    }
	}
    }
	  
    std::cout << "No such node " << data << "!" << std::endl;
}

void Hashtable::search(int data)
{
    int addr = h(data);
    if (table[addr])
    {
	Node *cur = table[addr];
	while (cur)
	{
	    if (cur->data == data) 
	    {
	        std::cout << "Node " << data << " is at key " << addr << std::endl;
		return;
	    }
	}
    }
    std::cout << "Node " << data << " is not in the table." << std::endl;
}

void Hashtable::print()
{
    for (int i = 0; i < maxSize; i++)
    {
	char buffer[50] = "NULL";
	std::cout << i << ": ";
	if (!table[i]) std::cout << buffer << std::endl;
	else
	{
	    Node *cur = table[i];
	    sprintf(buffer, "%d", cur->data);
	    std::cout << buffer;
	    cur = cur->next;
	    while (cur)
	    {
		sprintf(buffer, "%d", cur->data);
		std::cout << " -> " << buffer;
		cur = cur->next;
	    }
	    std::cout << std::endl;
	}
    }
}
