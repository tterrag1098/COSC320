#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
    list = NULL;
}

LinkedList::~LinkedList()
{
    while (list)
    {
        Node* n = list;
        list = n->next;
        delete n;
    }
}

Node* LinkedList::createNode(int id)
{
    return new Node(id);
}

Node* LinkedList::searchLocation(int id, bool eq)
{
    Node* n = list;
    if (n)
    {
        if (n->id >= id)
        {
            return NULL;
        }

        Node* search = n->next;
        while (search && search->id < id)
        {
            n = search;
            search = search->next;
        }

        return !eq || search->id == id ? n : NULL;
    }
    return n;
}

void LinkedList::insertNode(int id, StudentInfo info)
{
    Node* n = createNode(id);
    n->info = info;
    Node* insert = searchLocation(id, false);
    if (insert)
    {
        Node* prev_next = insert->next;
        insert->next = n;
        n->next = prev_next;
    }
    else
    {
        Node* prev_root = list;
        list = n;
        list->next = prev_root;
    }
}

void LinkedList::searchNode(int id)
{
    Node* found = searchLocation(id, true);
    if (found && found->next)
    {
        found->next->print();
    }
    else if (list && list->id == id)
    {
        list->print();
    }
    else
    {
        std::cout << "Data is not available in the list" << std::endl;
    }
}

void LinkedList::deleteNode(int id)
{
    if (list && id == list->id)
    {
        list->print();
        list = list->next;
        return;
    }

    Node* found = searchLocation(id, true);
    if (found && found->next && found->next->id == id)
    {
        Node* removed = found->next;
        found->next = removed->next;
        removed->print();
    }
    else
    {
        std::cout << "No such element by that id" << std::endl;
    }
}

void LinkedList::print()
{
    Node* root = list;

    if (!root)
    {
        std::cout << "Empty!" << std::endl;
        return;
    }

    while (root)
    {
        root->print();
        root = root->next;
    }
}
