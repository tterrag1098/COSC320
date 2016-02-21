#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class Printable
{
    public:
        virtual void print() = 0;
};

template <typename T>
class LinkedList : public Printable
{
    static_assert(std::is_base_of<Printable, T>::value, "T must derive from Drawable");

    public:
        LinkedList();
        ~LinkedList();
        void insertNode(int id, T data);
        void deleteNode(int id);
        void print() override;
        void searchNode(int id);
    private:
        Node<T>* list;
        Node<T>* createNode(int id);
        Node<T>* searchLocation(int id, bool eq);
};

#endif // LINKEDLIST_H
