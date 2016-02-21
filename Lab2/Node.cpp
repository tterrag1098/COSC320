#include "Node.h"
#include <iostream>

template <typename T>
Node<T>::Node(int id) : id(id){}

template <typename T>
Node<T>::~Node(){}

// Print the ID and the student info
template <typename T>
void Node<T>::print()
{
    std::cout << "ID: " << id << " -> ";
    data.print();
}

