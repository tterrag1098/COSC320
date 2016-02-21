#include "LinkedList.h"
#include "Node.cpp"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList()
{
    list = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (list)
    {
        Node<T>* n = list;
        list = n->next;
        delete n;
    }
}

template <typename T>
Node<T>* LinkedList<T>::createNode(int id)
{
    return new Node<T>(id);
}

/*
 Boolean is to search for equals or insert location.

 If true, the method will return NULL if there is no node with the given ID.
 If false, the method will return the last node that is less than the given ID.

 This method NEVER returns the exact node requested, but instead the previous one.
 This is to allow proper context to add/remove nodes.
*/
template <typename T>
Node<T>* LinkedList<T>::searchLocation(int id, bool eq)
{
    Node<T>* n = list;
    if (n)
    {
        // If the root node ID is greater than the search ID, short circuit and return NULL
        // Calling methods handle this return properly
        if (n->id >= id)
        {
            return NULL;
        }

        Node<T>* search = n->next;
        // Iterate through the nodes until we reach one that is greater than or equal to the given node
        while (search && search->id < id)
        {
            n = search;
            search = search->next;
        }

        // If eq is true, we must check that the next node has an equal ID. If so, return the node. Otherwise return null.
        return !eq || search->id == id ? n : NULL;
    }
    return n;
}

template <typename T>
void LinkedList<T>::insertNode(int id, T data)
{
    Node<T>* n = createNode(id);
    n->data = data;
    // Find the node before our insert location
    Node<T>* insert = searchLocation(id, false);
    if (insert)
    {
        // Cache the previous next value
        Node<T>* prev_next = insert->next;
        // Insert the new node between the found node and its next
        insert->next = n;
        // Set the new node's next to the cached one
        n->next = prev_next;
    }
    else
    {
        // If searchLocation returned null, this can only mean that the entire list is greater than the given ID
        // Since this is the case, we must replace the root
        Node<T>* prev_root = list;
        list = n;
        // And set the second element of the list to the old root
        list->next = prev_root;
    }
}

template <typename T>
void LinkedList<T>::searchNode(int id)
{
    // Search for a node with forced equality
    Node<T>* found = searchLocation(id, true);
    // If the found node's next is not NULL it must be equal by the contract of searchLocation
    if (found && found->next)
    {
        // So print out this node
        found->next->print();
    }
    // If searchLocation returned NULL, this could mean that the root node matches the given ID
    else if (list && list->id == id)
    {
        // So print out the root
        list->print();
    }
    // Otherwise, no node with the given ID was found
    else
    {
        std::cout << "Data is not available in the list" << std::endl;
    }
}

template <typename T>
void LinkedList<T>::deleteNode(int id)
{
    // If the root matches the given ID, short circuit and perform special logic for root deletion
    if (list && id == list->id)
    {
        // Set the new root to the old root's next, then delete the old reference
        Node<T>* old = list;
        list = list->next;
        old->print();
        delete old;
        return;
    }

    // Search for a node with forced equality
    Node<T>* found = searchLocation(id, true);
    // If the found node's next is not NULL it must be equal by the contract of searchLocation
    if (found && found->next)
    {
        // Set the found node's next to its next's next. This cuts the removed node out of the list and effectively removes it
        Node<T>* removed = found->next;
        found->next = removed->next;
        // Finally print and delete the node
        removed->print();
        delete removed;
    }
    else
    {
        std::cout << "No such element by that id" << std::endl;
    }
}

template <typename T>
void LinkedList<T>::print()
{
    Node<T>* root = list;

    // Special case for empty list
    if (!root)
    {
        std::cout << "Empty!" << std::endl;
        return;
    }

    // Iterate through the list and print each node
    while (root)
    {
        root->print();
        root = root->next;
    }
}
