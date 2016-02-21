#ifndef NODE_H
#define NODE_H

#include <string>

template <typename T>
class Node
{
    template<typename X>
    friend class LinkedList;
    private:
        Node(int id);
        ~Node();
        int id;
        T data;
        Node<T>* next;
        void print();
};

#endif // NODE_H
